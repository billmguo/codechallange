Normal one 

#define N 8192
#define BLOCK_SIZE 32
 
__global__ void matrix_mul_kernel(int* A, int* B,int* C)
{
        long row=blockIdx.y*blockDim.y+threadIdx.y;
        long col=blockIdx.x*blockDim.x+threadIdx.x;
 
        int i=0;
        int csum=0;
        for(i=0;i<N;i++)
        {
                csum+=A[row*N+i]*B[i*N+col];
        }
 
        C[row*N+col]=csum;
}




二、矩阵分块
       由于每个线程都要读取A的一行和B的一列，A的每一个行都要从全局存储中被读取N次，这样会极大影响性能。所以考虑矩阵分块，将数据块首先读取到shared memory中。然后在计算C矩阵的部分和。如下图：

       要计算C矩阵的一个块（图中C矩阵的灰色块），

        1、每一个block读取A的一个块subA（图中A矩阵的0号灰色块）和B的一个块subB（图中B矩阵的0号灰色块）到 shared memory中。

        2、block中每一个线程计算subA的一行与subB的一列，这样得到了C的部分和。

        3、计算完A和B 的0号块，再读取A和B的1号块，继续计算，依次类推计算2、3号块。


#define N 8192
#define BLOCK_SIZE 32
 
__global__ void matrix_mul_kernel(int* a, int* b,int* c)
{
        int tx=threadIdx.x;
        int ty=threadIdx.y;
 
        int bx=blockIdx.x;
        int by=blockIdx.y;
 
        int astart=blockIdx.y*BLOCK_SIZE*N;//获取A矩阵中0号块的起始位置，对应图中的A矩阵0号块的左上角的红红色圆点
        int bstart=blockIdx.x*BLOCK_SIZE;//获取B矩阵中0号块的起始位置，对应图中的B矩阵0号块的左上角的红红色圆点
 
        int astep=BLOCK_SIZE;   //每两个块之间的步长
        int bstep=BLOCK_SIZE*N; //每两个块之间的步长 （在内存中是按行存储，因此要乘以个N）
 
        int csub=0;
 
        __shared__ int A[BLOCK_SIZE][BLOCK_SIZE];//在shared memory 中创建subA所需空间
        __shared__ int B[BLOCK_SIZE][BLOCK_SIZE];
 
        int nblock=N/BLOCK_SIZE;
        int k=0;
        int i=0;
        for(k=0;k<nblock;k++)
        {
                A[ty][tx]=a[astart+k*astep+ty*N+tx];//如果对这个是怎么计算的不理解看下面的注释a[astart+k*astep+ty*N+tx]
                B[ty][tx]=b[bstart+k*bstep+ty*N+tx];
 
                 __syncthreads();
 
                for(i=0;i<BLOCK_SIZE;i++)
                {
                        csub+=A[ty][i]*B[i][tx];
                }
                __syncthreads();
           }
 
 
        int cstart=by*BLOCK_SIZE*N+BLOCK_SIZE*bx;
 
        c[cstart+ty*N+tx]=csub;
 
