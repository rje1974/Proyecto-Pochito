#ifndef _ROS_SERVICE_CheckPointAccessibility_h
#define _ROS_SERVICE_CheckPointAccessibility_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose2D.h"

namespace cob_map_accessibility_analysis
{

static const char CHECKPOINTACCESSIBILITY[] = "cob_map_accessibility_analysis/CheckPointAccessibility";

  class CheckPointAccessibilityRequest : public ros::Msg
  {
    public:
      uint32_t points_to_check_length;
      typedef geometry_msgs::Pose2D _points_to_check_type;
      _points_to_check_type st_points_to_check;
      _points_to_check_type * points_to_check;
      typedef bool _approach_path_accessibility_check_type;
      _approach_path_accessibility_check_type approach_path_accessibility_check;

    CheckPointAccessibilityRequest():
      points_to_check_length(0), points_to_check(NULL),
      approach_path_accessibility_check(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->points_to_check_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->points_to_check_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->points_to_check_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->points_to_check_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->points_to_check_length);
      for( uint32_t i = 0; i < points_to_check_length; i++){
      offset += this->points_to_check[i].serialize(outbuffer + offset);
      }
      union {
        bool real;
        uint8_t base;
      } u_approach_path_accessibility_check;
      u_approach_path_accessibility_check.real = this->approach_path_accessibility_check;
      *(outbuffer + offset + 0) = (u_approach_path_accessibility_check.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->approach_path_accessibility_check);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t points_to_check_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      points_to_check_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      points_to_check_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      points_to_check_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->points_to_check_length);
      if(points_to_check_lengthT > points_to_check_length)
        this->points_to_check = (geometry_msgs::Pose2D*)realloc(this->points_to_check, points_to_check_lengthT * sizeof(geometry_msgs::Pose2D));
      points_to_check_length = points_to_check_lengthT;
      for( uint32_t i = 0; i < points_to_check_length; i++){
      offset += this->st_points_to_check.deserialize(inbuffer + offset);
        memcpy( &(this->points_to_check[i]), &(this->st_points_to_check), sizeof(geometry_msgs::Pose2D));
      }
      union {
        bool real;
        uint8_t base;
      } u_approach_path_accessibility_check;
      u_approach_path_accessibility_check.base = 0;
      u_approach_path_accessibility_check.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->approach_path_accessibility_check = u_approach_path_accessibility_check.real;
      offset += sizeof(this->approach_path_accessibility_check);
     return offset;
    }

    const char * getType(){ return CHECKPOINTACCESSIBILITY; };
    const char * getMD5(){ return "b406244933de86ab08575478d23717b7"; };

  };

  class CheckPointAccessibilityResponse : public ros::Msg
  {
    public:
      uint32_t accessibility_flags_length;
      typedef bool _accessibility_flags_type;
      _accessibility_flags_type st_accessibility_flags;
      _accessibility_flags_type * accessibility_flags;

    CheckPointAccessibilityResponse():
      accessibility_flags_length(0), accessibility_flags(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->accessibility_flags_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->accessibility_flags_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->accessibility_flags_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->accessibility_flags_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->accessibility_flags_length);
      for( uint32_t i = 0; i < accessibility_flags_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_accessibility_flagsi;
      u_accessibility_flagsi.real = this->accessibility_flags[i];
      *(outbuffer + offset + 0) = (u_accessibility_flagsi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->accessibility_flags[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t accessibility_flags_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      accessibility_flags_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      accessibility_flags_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      accessibility_flags_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->accessibility_flags_length);
      if(accessibility_flags_lengthT > accessibility_flags_length)
        this->accessibility_flags = (bool*)realloc(this->accessibility_flags, accessibility_flags_lengthT * sizeof(bool));
      accessibility_flags_length = accessibility_flags_lengthT;
      for( uint32_t i = 0; i < accessibility_flags_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_accessibility_flags;
      u_st_accessibility_flags.base = 0;
      u_st_accessibility_flags.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_accessibility_flags = u_st_accessibility_flags.real;
      offset += sizeof(this->st_accessibility_flags);
        memcpy( &(this->accessibility_flags[i]), &(this->st_accessibility_flags), sizeof(bool));
      }
     return offset;
    }

    const char * getType(){ return CHECKPOINTACCESSIBILITY; };
    const char * getMD5(){ return "5f3c377d86bd78d373d82f6a042c05ca"; };

  };

  class CheckPointAccessibility {
    public:
    typedef CheckPointAccessibilityRequest Request;
    typedef CheckPointAccessibilityResponse Response;
  };

}
#endif
