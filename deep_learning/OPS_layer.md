SNPE

Firstparty/dsp is DSP side implementation, Firstparty/ML is CPU side implementation,  CPU layer abstract DNNruntime , D
SP abstract interface  

Firstparty/dsp

              Dsp<layername>Layer.hpp : the header file with declarations of the parameters, inputs and output tensors  for the layer
              Dsp<layername>Layer.cpp : the input and output tensor assignment and nngraph node creation stuff for the layer using the OP_<layername> enum in the AddQuantizedNodes() function
              In addition, the following files need to be edited:
              interface/DspInterface.hpp : Add an enum for the DSP_<layername>_LAYER and a struct for the parameters called <layername>_params that the CPU can use to call the DSP layer and assign parameters
              src/net/NeuralNetwork.cpp : Add a case statement that uses the DSP_<layername>_LAYER enum to return a Dsp<layername>Layer 
              files.min : add src/layers/Dsp<layername>Layer.cpp here so that it gets built  when building just the dsp
              files.min.in  : add src/layers/Dsp<layername>Layer.cpp here so that it gets built with SNPE 
              
Firstparty/ML

              <layername>LayerDsp.hpp : the header file with declarations of the  <layername>_params struct (defined above) parameters for the layer
              <layername>LayerDsp.cpp : the parameter assignment to the <layername>_params struct defined above  for the layer. Must call the LayerDsp constructor with the DSP_<layername>_LAYER enum declared above
              In addition, the following files need to be edited:
              DnnRuntime/src/DSP/NeuralNetworkDsp/NeuralNetworkDsp.hpp : Add an override for the Add<layername>Layer() function
              DnnRuntime/src/DSP/NeuralNetworkDsp/NeuralNetworkDsp.cpp :  implement the above function
              DnnRuntime/src/CMakeLists.txt : add DSP/NeuralNetworkDsp/<layername>LayerDsp.cpp here so that it gets built with SNPE
              DnnValidation/src/DspConstraint.cpp  : add a constraint for the layer
