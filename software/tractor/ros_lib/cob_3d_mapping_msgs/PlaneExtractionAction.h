#ifndef _ROS_cob_3d_mapping_msgs_PlaneExtractionAction_h
#define _ROS_cob_3d_mapping_msgs_PlaneExtractionAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "cob_3d_mapping_msgs/PlaneExtractionActionGoal.h"
#include "cob_3d_mapping_msgs/PlaneExtractionActionResult.h"
#include "cob_3d_mapping_msgs/PlaneExtractionActionFeedback.h"

namespace cob_3d_mapping_msgs
{

  class PlaneExtractionAction : public ros::Msg
  {
    public:
      typedef cob_3d_mapping_msgs::PlaneExtractionActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef cob_3d_mapping_msgs::PlaneExtractionActionResult _action_result_type;
      _action_result_type action_result;
      typedef cob_3d_mapping_msgs::PlaneExtractionActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    PlaneExtractionAction():
      action_goal(),
      action_result(),
      action_feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->action_goal.serialize(outbuffer + offset);
      offset += this->action_result.serialize(outbuffer + offset);
      offset += this->action_feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->action_goal.deserialize(inbuffer + offset);
      offset += this->action_result.deserialize(inbuffer + offset);
      offset += this->action_feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "cob_3d_mapping_msgs/PlaneExtractionAction"; };
    const char * getMD5(){ return "54e2a966f59a0375e770c2dd1d589ce3"; };

  };

}
#endif