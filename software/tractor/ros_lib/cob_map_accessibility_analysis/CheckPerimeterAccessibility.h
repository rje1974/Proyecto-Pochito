#ifndef _ROS_SERVICE_CheckPerimeterAccessibility_h
#define _ROS_SERVICE_CheckPerimeterAccessibility_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose2D.h"

namespace cob_map_accessibility_analysis
{

static const char CHECKPERIMETERACCESSIBILITY[] = "cob_map_accessibility_analysis/CheckPerimeterAccessibility";

  class CheckPerimeterAccessibilityRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose2D _center_type;
      _center_type center;
      typedef float _radius_type;
      _radius_type radius;
      typedef float _rotational_sampling_step_type;
      _rotational_sampling_step_type rotational_sampling_step;

    CheckPerimeterAccessibilityRequest():
      center(),
      radius(0),
      rotational_sampling_step(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->center.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->radius);
      offset += serializeAvrFloat64(outbuffer + offset, this->rotational_sampling_step);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->center.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->radius));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rotational_sampling_step));
     return offset;
    }

    const char * getType(){ return CHECKPERIMETERACCESSIBILITY; };
    const char * getMD5(){ return "59c2a8fc00319aae0b2c0c3073018e6e"; };

  };

  class CheckPerimeterAccessibilityResponse : public ros::Msg
  {
    public:
      uint32_t accessible_poses_on_perimeter_length;
      typedef geometry_msgs::Pose2D _accessible_poses_on_perimeter_type;
      _accessible_poses_on_perimeter_type st_accessible_poses_on_perimeter;
      _accessible_poses_on_perimeter_type * accessible_poses_on_perimeter;

    CheckPerimeterAccessibilityResponse():
      accessible_poses_on_perimeter_length(0), accessible_poses_on_perimeter(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->accessible_poses_on_perimeter_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->accessible_poses_on_perimeter_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->accessible_poses_on_perimeter_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->accessible_poses_on_perimeter_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->accessible_poses_on_perimeter_length);
      for( uint32_t i = 0; i < accessible_poses_on_perimeter_length; i++){
      offset += this->accessible_poses_on_perimeter[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t accessible_poses_on_perimeter_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      accessible_poses_on_perimeter_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      accessible_poses_on_perimeter_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      accessible_poses_on_perimeter_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->accessible_poses_on_perimeter_length);
      if(accessible_poses_on_perimeter_lengthT > accessible_poses_on_perimeter_length)
        this->accessible_poses_on_perimeter = (geometry_msgs::Pose2D*)realloc(this->accessible_poses_on_perimeter, accessible_poses_on_perimeter_lengthT * sizeof(geometry_msgs::Pose2D));
      accessible_poses_on_perimeter_length = accessible_poses_on_perimeter_lengthT;
      for( uint32_t i = 0; i < accessible_poses_on_perimeter_length; i++){
      offset += this->st_accessible_poses_on_perimeter.deserialize(inbuffer + offset);
        memcpy( &(this->accessible_poses_on_perimeter[i]), &(this->st_accessible_poses_on_perimeter), sizeof(geometry_msgs::Pose2D));
      }
     return offset;
    }

    const char * getType(){ return CHECKPERIMETERACCESSIBILITY; };
    const char * getMD5(){ return "0f2833ac60e33edc572866f291ef3669"; };

  };

  class CheckPerimeterAccessibility {
    public:
    typedef CheckPerimeterAccessibilityRequest Request;
    typedef CheckPerimeterAccessibilityResponse Response;
  };

}
#endif
