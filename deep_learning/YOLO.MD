Yolo V1

 link: darknet  https://pjreddie.com/darknet/yolov1/

Resize the image and slit the image into S*S grid, for each grid, use B anchor boxes and each boxes
 include (x, y, h, w, confidence) here, x, y, h, w are the shift to the bounding box,  normally we choose S = 7 , 
 B = 2, and C= 20(Pascal has 20 types), each anchor box have a confidence score to represent whether there has
  object in the box or not. if there has no object it is 0, or else it is IOU(box, ground truth box).

[Pc, x, y, w, h, c0 .. C20] , the above picture shows the S * S * (B *5 + C) here B is (Pc, x, y, w, h)


NMS:

For a certain category, select the bounding box with the highest score, and then calculate the IOU 
value of it and other bounding boxes. If the IOU is greater than 0.5, the repetition rate is greater, 
and the score is set to 0. If it is not greater than 0.5, it will not be changed; After one round, the 
largest bounding box in the remaining score is selected, and then the IOUs of the bounding box and other 
bounding boxes are calculated, and the above process is repeated. Finally, the 20 scores of each bounding
 box take the maximum score. If the score is greater than 0, then the bounding box is the corresponding 
 category of the score(the row of the matrix). If it is less than 0, just omit it.

Pr(class|Object) * Pr(object) * IOU(truth, predict) = Pr(class) * IOU(Truth, pred)

Pr(class) class information and second is IOU bounding box condience.  s

Weakness:

Small object detection accuracy , same as SSD .

  Recall rate is low.


Yolo V2
  https://github.com/shishichang/yolov2-tensorflow

1. Add batch normalization layer after each conv. mAP improve 2 percent.
2.Change the pretrained classification network with higher resolution 448*448. mAP improve 4 percent.
3. Remove the FC layer , use anchor boxes to predict the bounding boxes.
    a.input image resize to 416*416.
    b.Remove the last pooling layer
    c.Use conv layer to down sampling.  416*416 --> 13*13
each anchor boxes have its classification. Same as SSD

Direct location prediction

  Finally, Yolo2 will predict 5 bounding box and each box has 5 coordinator (tx, ty, tw, th, to)

  Fine-Grained Features

   Pass through layer, connect the early shallow conv to later conv layers.

  YOLO v2 predicted 13 x 13 x 5 = 845 boxes. At each grid cell, 5 boxes were detected using 5 anchors.

Yolo V3
  

  First, YOLO v3 uses a variant of Darknet, which originally has 53 layer network trained on Imagenet. 
  For the task of detection, 53 more layers are stacked onto it, giving us a 106 layer fully convolutional
  underlying architecture for YOLO v3. 


   The detection is done by applying 1 x 1 detection kernels on feature maps of three different sizes at three 
   different places in the network.

  The shape of the detection kernel is 1 x 1 x (B x (5 + C) ). Here B is the number of bounding boxes a cell on the 
  feature map can predict, “5” is for the 4 bounding box attributes and one object confidence, and C is the number of
  classes. In YOLO v3 trained on COCO, B = 3 and C = 80

YOLO v3 makes prediction at three scales, which are precisely given by downsampling the dimensions of the input image by
32, 16 and 8 respectively.

 1.One detection is made here using the 1 x 1 detection kernel, giving us a detection feature map of 13 x 13 x 255.

 2.The second detection is made by the 94th layer, yielding a detection feature map of 26 x 26 x 255

 3. the final of the 3 at 106th layer, yielding feature map of size 52 x 52 x 255.

The 13 x 13 layer is responsible for detecting large objects, whereas the 52 x 52 layer detects the smaller objects,
with the 26 x 26 layer detecting medium objects.

On the other hand YOLO v3 predicts boxes at 3 different scales. For the same image of 416 x 416, the number of predicted boxes 
are 10,647 (52*52*3 + 26*26*3 + 13*13*3). This means that YOLO v3 predicts 10x the number of boxes predicted by YOLO v2.

YOLO v3 performs at par with other state of art detectors like RetinaNet, while being considerably faster, at COCO mAP 50 
benchmark. It is also better than SSD and it’s variants.

Loss Function  Comparsion 
yolo v1 loss function

 1.The first one penalizes the objectness score prediction for bounding boxes responsible for predicting objects 
 (the scores for these should ideally be 1). the first line is (x,y) and second line is (h, w).
 2.The second one for bounding boxes having no objects, (the scores should ideally be zero). Include no object and 
 has object two cases, only calculate the maximum IOU
 3.The last one penalises the class prediction for the bounding box which predicts the objects.classification loss
The last three terms in YOLO v2 are the squared errors, whereas in YOLO v3, they’ve been replaced by cross-entropy 
error terms. In other words, object confidence and class predictions in YOLO v3 are now predicted through logistic regression.

