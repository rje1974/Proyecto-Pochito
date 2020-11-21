#ifndef _ROS_cob_3d_mapping_msgs_TriggerActionFeedback_h
#define _ROS_cob_3d_mapping_msgs_TriggerActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "cob_3d_mapping_msgs/TriggerFeedback.h"

namespace cob_3d_mapping_msgs
{

  class TriggerActionFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef cob_3d_mapping_msgs::TriggerFeedback _feedback_type;
      _feedback_type feedback;

    TriggerActionFeedback():
      header(),
      status(),
      feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "cob_3d_mapping_msgs/TriggerActionFeedback"; };
    const char * getMD5(){ return "fd657a69fe86b758d188e038f0b860e5"; };

  };

}
#endif