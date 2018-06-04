https://zhuanlan.zhihu.com/p/37074222
https://zhuanlan.zhihu.com/p/35700882
SqueezeNet

H*W*C->CONV 1x1 --> 

#params： 3/4 * C**2
#FLOPs： 3/4 * C**2 *H *W


Mobile Net
#params： 9* C + C**2
#FLOPs： (9* C + C**2)* H *W


DWCONV with bottle neck block
#params： 9*C +8*(C**2)
#FLOPs： (9*C + 8* C**2)* H* W

量化比特宽度减少时，权重对变化更敏感
8bit和7bit量化与浮点模型性能相当
当总bit深度相同时，保持权值和激活的bit深度相同时更好

https://zhuanlan.zhihu.com/p/35700882
