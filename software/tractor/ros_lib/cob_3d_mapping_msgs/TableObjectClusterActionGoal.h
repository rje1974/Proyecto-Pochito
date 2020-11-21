#ifndef _ROS_cob_3d_mapping_msgs_TableObjectClusterActionGoal_h
#define _ROS_cob_3d_mapping_msgs_TableObjectClusterActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "cob_3d_mapping_msgs/TableObjectClusterGoal.h"

namespace cob_3d_mapping_msgs
{

  class TableObjectClusterActionGoal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalID _goal_id_type;
      _goal_id_type goal_id;
      typedef cob_3d_mapping_msgs::TableObjectClusterGoal _goal_type;
      _goal_type goal;

    TableObjectClusterActionGoal():
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

    const char * getType(){ return "cob_3d_mapping_msgs/TableObjectClusterActionGoal"; };
    const char * getMD5(){ return "4425cec539a8383f41fe876cf2fb30e5"; };

  };

}
#endif