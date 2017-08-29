#include <vector>
#include <string>
#include <list>
#include <set>
using namespace std;

typedef pair<int,int> pp;
class Soultion{
public:
	int move(string direction) {
		if (direction.size() < 1)
			return -1;
		for (auto d:direction){
			pp shift = getshift(d);
			if (shift.first == -1 && shift.second == -1)
				break;;
			pp next = snake.back();
		
			next.first += shift.first;
			next.second += shift.second;

			if (!isvalid(next) || clash(next))
				break;;
			if (food.count(next) == 0) {
				snake.pop_front();
			}else {
				food.erase(next);
				score++;
			}
		}
		return score;
	}

private:
	pp getshift(char &d) {
		pp shift;
		switch(d){
			case 'U':
				shift = {0,-1};
				break;
			case 'D':
				shift = {0, 1};
				break;
			case 'L':
				shift = {-1,0};
				break;
			case 'R':
				shift = {1, 0};
				break;
			default:
				shift = {-1,-1};
				break;
		}
		return shift;
	}
	bool isvalid(pp &newp) {
	 	if (newp.first >= width || newp.first < 0 || newp.second >= width || newp.second < 0)
			return false;
		return true; 
	}
	bool clash(pp &pos) {
		for (auto s:snake) {
			if (s.first == pos.first && s.second == pos.second)
				return true;
		}
		return false;
	}
	
	int width, height;
	set<pair<int,int>> food;
	list<pair<int,int>> snake;
	int food_idx;
	int score;

};

int main(){
	return 1;
}
