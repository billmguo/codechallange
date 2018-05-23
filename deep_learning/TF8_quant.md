TF quantization 
1. Download the model from http://download.tensorflow.org/models/mobilenet_v1_1.0_224_2017_06_14.tar.gz
2. Export the pb graph by https://github.com/tensorflow/models/tree/master/research/slim#Export
3. Remove the minimum_size limitation for quantize_weights from https://github.com/tensorflow/tensorflow/blob/master/tensorflow/tools/graph_transforms/quantize_weights.cc#L40
4. Compile the graph_transorforms from (https://github.com/tensorflow/tensorflow/tree/master/tensorflow/tools/graph_transforms)
5. Apply the TF8 quantization:

bazel-bin/tensorflow/tools/graph_transforms/transform_graph --in_graph= frozen_mobilenet_v1_1.0_224.pb --out_graph=frozen_mobilenet_v1_1.0_224_quantized.pb --inputs='input' --outputs='MobilenetV1/Predictions/Reshape_1' --transforms=' add_default_attributes strip_unused_nodes(type=float, shape="1,224,224,3") remove_nodes(op=Identity, op=CheckNumerics, op=Squeeze) fold_constants(ignore_errors=true) fold_batch_norms fold_old_batch_norms quantize_weights quantize_nodes strip_unused_nodes sort_by_execution_order’

 Evaluate the frozen_mobilenet_v1_1.0_224_quantized.pb by your sample images or ImageNet2012 eval dataset
