public class HelloWorld {

    public static void main(String[] args) {
        myfunc(4);
    }
    
    public static void myfunc(int num) {
        int[] arr = new int[num * 2];
        boolean[] used = new boolean[num + 1];  // index 0 is not used
        myfunc(arr, used, 0);
    }
        
    public static void myfunc(int[] arr, boolean[] used, int nextAvailableIdx) {
        if (nextAvailableIdx == arr.length) {
            for (int i = 1; i < used.length; i++) {
                if (!used[i]) {
                    return;
                }
            }
            System.out.println(Arrays.toString(arr));
        }
        
        for (int tryNum = 1; tryNum < used.length; tryNum++) {
              int complimentIdx = nextAvailableIdx + tryNum + 1;
              if (used[tryNum] || complimentIdx >= arr.length || arr[complimentIdx] != 0) {
                continue;
              }
              arr[nextAvailableIdx] = tryNum;
              arr[complimentIdx] = tryNum;
              used[tryNum] = true;
              int j = nextAvailableIdx + 1;
              while (j < arr.length && arr[j] != 0) {
                j++;
              }
              myfunc(arr, used, j);
              arr[nextAvailableIdx] = 0;
              arr[complimentIdx] = 0;
              used[tryNum] = false;
        }
    }
}
