#ifndef _ROS_cob_object_detection_msgs_TrainObjectResult_h
#define _ROS_cob_object_detection_msgs_TrainObjectResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cob_object_detection_msgs
{

  class TrainObjectResult : public ros::Msg
  {
    public:

    TrainObjectResult()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return "cob_object_detection_msgs/TrainObjectResult"; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

}
#endif