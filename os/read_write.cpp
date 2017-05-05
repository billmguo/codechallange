size_t flip_read(struct file *file, char __user *buf, size_t size, loff_t *pos) {
	int r_size, t_size;
	r_size = lbuff_size  - (int) (*pos); //byte left;
 	if ( r_size == 0 )
		return 0;
	t_size = min(r_size, size);
	if (copy_to_user(buf,lbuff + *pos, size) {
		return E_FAULT;
	else {
		*pos += t_size;
		 return t_size;
	}
}


size_t flip_write(struct file *file, char __user *buf,size_t size, loff_t *pos) {
	int r_size;
	r_size = lbuff_size - *pos;
	if (size  > r_size) 
		return -EIO;
    if (copy_from_user(lbuff + *pos, buf, size){
		return -EFAULT;
	} else {
		*pos += size;
		return size;
	}
} 
