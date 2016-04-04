/*give 1 meter walkroad, and 
randomly generate rain, the rain is 1 cm. simulate how many rain drops to cover all the 1 meter [-0.01~1].
*/

class solution{
struct interval {
    double left, right;
    bool isWet() {
        return left>=right;
    }
    interval():left(0),right(0.01){};
};


void fill(){
    vector<interval> sidewalk(100,interval());
    int cnt=0, wetCnt=0, idx;
    while(wetCnt<100) {
        ++cnt;
        double p= (double)(rand())/RAND_MAX;
        double left=p-0.005;
        double right=p+0.005;
        if(left>=0) {
            idx=left/0.01;
            if(!sidewalk[idx].isWet()) {
                iright=left-idx*0.01;
                if (iright<sidewalk[idx].right) {
                    sidewalk[idx].right=iright;
                    if(sidewalk[idx].wet())
                        ++wetCnt;
                }
            }
        }
        
        if(right<=1) {
            idx=right/0.01;
            if(!sidewalk[idx].wet()) {
                ileft=right-idx*0.01;
                    if (ileft>sidewalk[idx].left) {
                        sidewalk[idx].left=ileft;
                        if(sidewalk[idx].isWet()) 
                            ++wetCnt;
                    }
            }
        }
    }        

}  
};      
