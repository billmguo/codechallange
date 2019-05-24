public class KMAlgorithm {
	@Test
	public void test() {
//		char[][] graph = new char[][] {
//			{'O', 'P', 'O', 'B', 'P', 'O', 'P'},
//			{'O', 'O', 'O', 'O', 'O', 'O', 'O'},
//			{'B', 'O', 'O', 'B', 'O', 'O', 'B'}
//		};
		char[][] graph = new char[][] {
			{'P', 'O', 'O', 'B', 'P', 'O', 'B'}
		};
		System.out.println(match(graph));
	}
	
	char[][] graph;
	List<int[]> bikes;
	List<int[]> persons;
	int[][] G;
	int[] personExpect;
	int[] bikeExpect;
	boolean[] visitedPerson;
	boolean[] visitedBike;
	int[] match;
	int[] slack; 
	//return : person[i, j] + bike[i, j]
	public List<List<Integer>> match(char[][] graph) {
		this.graph = graph;
		init();
		KM();
		List<List<Integer>> res = new ArrayList<>();
		for(int i = 0 ; i < match.length ; i++) {
			if(match[i] == -1) continue;
			int[] person = persons.get(match[i]);
			int[] bike = bikes.get(i);
			res.add(Arrays.asList(person[0], person[1], bike[0], bike[1]));
		}
		return res;
		
	}
	private void init() {
		int rows = graph.length;
		int cols = graph[0].length;
		persons = new ArrayList<>();
		bikes = new ArrayList<>();
		for(int i = 0 ; i < rows ; i++) {
			for(int j = 0 ; j < cols ; j++) {
				if(graph[i][j] == 'P') {
					persons.add(new int[] {i, j});
				}
				if(graph[i][j] == 'B') {
					bikes.add(new int[] {i, j});
				}
			}
		}
		// build cost graph
		G = new int[persons.size()][bikes.size()];
		for(int i = 0 ; i < G.length ; i++) {
			for(int j = 0 ; j < G[0].length ; j++) {
				int[] person = persons.get(i);
				int[] bike = bikes.get(j);
				int dis = Math.abs(person[0] - bike[0]) + Math.abs(person[1] - bike[1]);
				G[i][j] = -dis;   // 求最小距离，所以这里权值用负数表示
			}
		}
		personExpect = new int[persons.size()];
		bikeExpect  = new int[bikes.size()];
		visitedPerson = new boolean[persons.size()];
		visitedBike = new boolean[bikes.size()];
		match = new int[bikes.size()];
		Arrays.fill(match, -1);
		slack = new int[bikes.size()];
		Arrays.fill(slack, Integer.MAX_VALUE);

		// init person expectation array
		for(int i = 0 ; i < persons.size() ; i++) {
			personExpect[i] = G[i][0];
			for(int j = 0 ; j < bikes.size() ; j++) {
				personExpect[i] = Math.max(personExpect[i], G[i][j]);
			}
		}
	}
	boolean find(int person) {
		visitedPerson[person] = true;
		for(int bike = 0 ; bike < bikes.size() ; bike++) {
			if(visitedBike[bike]) continue;
			int gap = personExpect[person] + bikeExpect[bike] - G[person][bike];
			if(gap == 0) {
				visitedBike[bike] = true;
				if(match[bike] == -1 || find(match[bike])) {
					match[bike] = person;
					return true;
				}
			} else {
				slack[bike] = Math.min(slack[bike], gap);
			}
		}
		return false;
	}
	void KM() {
		for(int i = 0 ; i < persons.size() ; i++) {
			Arrays.fill(slack, Integer.MAX_VALUE);
			// assign bike for each person
			while(true) {
				Arrays.fill(visitedPerson, false);
				Arrays.fill(visitedBike, false);
				if(find(i)) break;
				// if can not assign one bike to the person, decrease the expectation
				int tmp = Integer.MAX_VALUE;
				for(int bike = 0; bike < bikes.size() ; bike++) {
					if(!visitedBike[bike]) tmp = Math.min(tmp, slack[bike]);
				}
				for(int person = 0 ; person < persons.size() ; person++) {
					if(visitedPerson[person]) {
						personExpect[person] -= tmp;
					}
				}
				for(int bike = 0 ; bike < bikes.size() ; bike++) {
					if(visitedBike[bike]) {
						bikeExpect[bike] += tmp;
					} else {
						slack[bike] -= tmp;
					}
				}
			}
		}
	}
}
