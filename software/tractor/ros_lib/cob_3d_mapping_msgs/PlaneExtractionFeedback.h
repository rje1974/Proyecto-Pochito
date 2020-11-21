#ifndef _ROS_cob_3d_mapping_msgs_PlaneExtractionFeedback_h
#define _ROS_cob_3d_mapping_msgs_PlaneExtractionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"

namespace cob_3d_mapping_msgs
{

  class PlaneExtractionFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::String _currentStep_type;
      _currentStep_type currentStep;

    PlaneExtractionFeedback():
      currentStep()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->currentStep.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->currentStep.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "cob_3d_mapping_msgs/PlaneExtractionFeedback"; };
    const char * getMD5(){ return "7c51960fbfdc31dbfce9bf929242f080"; };

  };

}
#endif