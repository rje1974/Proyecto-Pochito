#ifndef _ROS_cob_mimic_SetMimicAction_h
#define _ROS_cob_mimic_SetMimicAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "cob_mimic/SetMimicActionGoal.h"
#include "cob_mimic/SetMimicActionResult.h"
#include "cob_mimic/SetMimicActionFeedback.h"

namespace cob_mimic
{

  class SetMimicAction : public ros::Msg
  {
    public:
      typedef cob_mimic::SetMimicActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef cob_mimic::SetMimicActionResult _action_result_type;
      _action_result_type action_result;
      typedef cob_mimic::SetMimicActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    SetMimicAction():
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

    const char * getType(){ return "cob_mimic/SetMimicAction"; };
    const char * getMD5(){ return "bcce0cdfbf604e56a24465f9095fb580"; };

  };

}
#endif