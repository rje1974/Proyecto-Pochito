#ifndef _ROS_cob_script_server_ScriptGoal_h
#define _ROS_cob_script_server_ScriptGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cob_script_server
{

  class ScriptGoal : public ros::Msg
  {
    public:
      typedef const char* _function_name_type;
      _function_name_type function_name;
      typedef const char* _component_name_type;
      _component_name_type component_name;
      typedef const char* _parameter_name_type;
      _parameter_name_type parameter_name;
      typedef const char* _mode_type;
      _mode_type mode;
      typedef const char* _service_name_type;
      _service_name_type service_name;
      typedef float _duration_type;
      _duration_type duration;
      typedef bool _planning_type;
      _planning_type planning;

    ScriptGoal():
      function_name(""),
      component_name(""),
      parameter_name(""),
      mode(""),
      service_name(""),
      duration(0),
      planning(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_function_name = strlen(this->function_name);
      varToArr(outbuffer + offset, length_function_name);
      offset += 4;
      memcpy(outbuffer + offset, this->function_name, length_function_name);
      offset += length_function_name;
      uint32_t length_component_name = strlen(this->component_name);
      varToArr(outbuffer + offset, length_component_name);
      offset += 4;
      memcpy(outbuffer + offset, this->component_name, length_component_name);
      offset += length_component_name;
      uint32_t length_parameter_name = strlen(this->parameter_name);
      varToArr(outbuffer + offset, length_parameter_name);
      offset += 4;
      memcpy(outbuffer + offset, this->parameter_name, length_parameter_name);
      offset += length_parameter_name;
      uint32_t length_mode = strlen(this->mode);
      varToArr(outbuffer + offset, length_mode);
      offset += 4;
      memcpy(outbuffer + offset, this->mode, length_mode);
      offset += length_mode;
      uint32_t length_service_name = strlen(this->service_name);
      varToArr(outbuffer + offset, length_service_name);
      offset += 4;
      memcpy(outbuffer + offset, this->service_name, length_service_name);
      offset += length_service_name;
      union {
        float real;
        uint32_t base;
      } u_duration;
      u_duration.real = this->duration;
      *(outbuffer + offset + 0) = (u_duration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_duration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_duration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_duration.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->duration);
      union {
        bool real;
        uint8_t base;
      } u_planning;
      u_planning.real = this->planning;
      *(outbuffer + offset + 0) = (u_planning.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->planning);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_function_name;
      arrToVar(length_function_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_function_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_function_name-1]=0;
      this->function_name = (char *)(inbuffer + offset-1);
      offset += length_function_name;
      uint32_t length_component_name;
      arrToVar(length_component_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_component_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_component_name-1]=0;
      this->component_name = (char *)(inbuffer + offset-1);
      offset += length_component_name;
      uint32_t length_parameter_name;
      arrToVar(length_parameter_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_parameter_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_parameter_name-1]=0;
      this->parameter_name = (char *)(inbuffer + offset-1);
      offset += length_parameter_name;
      uint32_t length_mode;
      arrToVar(length_mode, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_mode; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_mode-1]=0;
      this->mode = (char *)(inbuffer + offset-1);
      offset += length_mode;
      uint32_t length_service_name;
      arrToVar(length_service_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_service_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_service_name-1]=0;
      this->service_name = (char *)(inbuffer + offset-1);
      offset += length_service_name;
      union {
        float real;
        uint32_t base;
      } u_duration;
      u_duration.base = 0;
      u_duration.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_duration.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_duration.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_duration.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->duration = u_duration.real;
      offset += sizeof(this->duration);
      union {
        bool real;
        uint8_t base;
      } u_planning;
      u_planning.base = 0;
      u_planning.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->planning = u_planning.real;
      offset += sizeof(this->planning);
     return offset;
    }

    const char * getType(){ return "cob_script_server/ScriptGoal"; };
    const char * getMD5(){ return "0a40a194b72e6783b1b8bec8d1c28c7f"; };

  };

}
#endif