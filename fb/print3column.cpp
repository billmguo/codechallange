void print_3column(string str) {
        int N = str.size();
        int r = N / 3;
        int ext = N % 3;
        int total = 0;
        for (int i = 0; i < r + (ext ? 1 : 0); ++i) {
            for (int j = 0; j < 3 && total < N; ++j) {
                int index = j * r + min(j, ext) + i; 
                cout<<str[index]<<index<<" ";
                ++total;
            }
            cout<<endl;
        }
}        
