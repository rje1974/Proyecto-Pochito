#ifndef _ROS_cob_3d_mapping_msgs_TriggerActionGoal_h
#define _ROS_cob_3d_mapping_msgs_TriggerActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "cob_3d_mapping_msgs/TriggerGoal.h"

namespace cob_3d_mapping_msgs
{

  class TriggerActionGoal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalID _goal_id_type;
      _goal_id_type goal_id;
      typedef cob_3d_mapping_msgs::TriggerGoal _goal_type;
      _goal_type goal;

    TriggerActionGoal():
      header(),
      goal_id(),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal_id.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal_id.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "cob_3d_mapping_msgs/TriggerActionGoal"; };
    const char * getMD5(){ return "2f878de462585b22b38af1fb7eda1f12"; };

  };

}
#endif