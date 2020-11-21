#ifndef _ROS_cob_object_detection_msgs_DetectObjectsResult_h
#define _ROS_cob_object_detection_msgs_DetectObjectsResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "cob_object_detection_msgs/DetectionArray.h"

namespace cob_object_detection_msgs
{

  class DetectObjectsResult : public ros::Msg
  {
    public:
      typedef cob_object_detection_msgs::DetectionArray _object_list_type;
      _object_list_type object_list;

    DetectObjectsResult():
      object_list()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->object_list.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->object_list.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "cob_object_detection_msgs/DetectObjectsResult"; };
    const char * getMD5(){ return "6da5c76956a10a2b2a7e649614ba9504"; };

  };

}
#endif