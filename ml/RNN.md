RNN accelerating on GPU
http://www.robots.ox.ac.uk/~seminars/seminars/Extra/2015_10_08_JeremyAppleyard.pdf



RNN parameters and MAC calculation 


enter image description here



num_params = [(num_units + input_dim + 1) * num_units] * 4
4 means we have different weight and bias variables for 3 gates (read / write / froget) and - 4-th - for the cell state (within same hidden state). (These mentioned are shared among timesteps along particular hidden state vector)

+ 1: bias
* 4: there are 4 neural network layers (yellow box) {W_forget, W_input, W_output, W_cell}

model.add(LSTM(units=256, input_dim=4096, input_length=16))
[(256 + 4096 + 1) * 256] * 4 = 4457472 Bytes
The input_length as no effect on the parameters as the same weight matrix would be reused for the input_length 



How to calculate the total MAC


Total flops = 8*(time_steps * Batch * num_units * num_units + time_steps*batch*num_units)

model.add(LSTM(units=256, input_dim=4096, input_length=16))
here units is hidden_unit, input_dim = input feature dim, input_length = time stamps. 
Time steps - This is equivalent to the amount of time steps you run your recurrent neural network. If you want your network to have memory of 60 characters, this number should be 60. here is same as input_length.

Hidden unit(num_units) the number of nodes in hidden layer of a feed forward neural network is equivalent to num_units number of LSTM units in a LSTM cell at every time step of the network

for the above case (Batch_size=1)*8*(16*256*256 + 16*4096*256) = 142 606 336 = 142MFLOPS 
