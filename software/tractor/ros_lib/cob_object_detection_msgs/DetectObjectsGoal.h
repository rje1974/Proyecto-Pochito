#ifndef _ROS_cob_object_detection_msgs_DetectObjectsGoal_h
#define _ROS_cob_object_detection_msgs_DetectObjectsGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"

namespace cob_object_detection_msgs
{

  class DetectObjectsGoal : public ros::Msg
  {
    public:
      typedef std_msgs::String _object_name_type;
      _object_name_type object_name;

    DetectObjectsGoal():
      object_name()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->object_name.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->object_name.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "cob_object_detection_msgs/DetectObjectsGoal"; };
    const char * getMD5(){ return "adb33ef101026c3e15d799e3decf403f"; };

  };

}
#endif