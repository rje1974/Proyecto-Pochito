#ifndef _ROS_cob_sound_SayAction_h
#define _ROS_cob_sound_SayAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "cob_sound/SayActionGoal.h"
#include "cob_sound/SayActionResult.h"
#include "cob_sound/SayActionFeedback.h"

namespace cob_sound
{

  class SayAction : public ros::Msg
  {
    public:
      typedef cob_sound::SayActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef cob_sound::SayActionResult _action_result_type;
      _action_result_type action_result;
      typedef cob_sound::SayActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    SayAction():
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

    const char * getType(){ return "cob_sound/SayAction"; };
    const char * getMD5(){ return "a4abbdabc60e2aa0d20e8270a11de784"; };

  };

}
#endif