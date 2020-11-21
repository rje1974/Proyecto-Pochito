#ifndef _ROS_cob_3d_mapping_msgs_TriggerResult_h
#define _ROS_cob_3d_mapping_msgs_TriggerResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"

namespace cob_3d_mapping_msgs
{

  class TriggerResult : public ros::Msg
  {
    public:
      typedef std_msgs::String _message_type;
      _message_type message;

    TriggerResult():
      message()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->message.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->message.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "cob_3d_mapping_msgs/TriggerResult"; };
    const char * getMD5(){ return "d8c2dd3109bf1dc2423499244e4009cf"; };

  };

}
#endif