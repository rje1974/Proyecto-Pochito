#ifndef _ROS_cob_script_server_ScriptState_h
#define _ROS_cob_script_server_ScriptState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cob_script_server
{

  class ScriptState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int16_t _number_type;
      _number_type number;
      typedef const char* _function_name_type;
      _function_name_type function_name;
      typedef const char* _component_name_type;
      _component_name_type component_name;
      typedef const char* _parameter_name_type;
      _parameter_name_type parameter_name;
      typedef const char* _full_graph_name_type;
      _full_graph_name_type full_graph_name;
      typedef int8_t _state_type;
      _state_type state;
      typedef int16_t _error_code_type;
      _error_code_type error_code;
      enum { UNKNOWN = 0 };
      enum { ACTIVE = 1 };
      enum { SUCCEEDED = 2 };
      enum { FAILED = 3 };
      enum { PAUSED = 4 };

    ScriptState():
      header(),
      number(0),
      function_name(""),
      component_name(""),
      parameter_name(""),
      full_graph_name(""),
      state(0),
      error_code(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_number;
      u_number.real = this->number;
      *(outbuffer + offset + 0) = (u_number.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_number.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->number);
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
      uint32_t length_full_graph_name = strlen(this->full_graph_name);
      varToArr(outbuffer + offset, length_full_graph_name);
      offset += 4;
      memcpy(outbuffer + offset, this->full_graph_name, length_full_graph_name);
      offset += length_full_graph_name;
      union {
        int8_t real;
        uint8_t base;
      } u_state;
      u_state.real = this->state;
      *(outbuffer + offset + 0) = (u_state.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->state);
      union {
        int16_t real;
        uint16_t base;
      } u_error_code;
      u_error_code.real = this->error_code;
      *(outbuffer + offset + 0) = (u_error_code.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_error_code.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->error_code);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_number;
      u_number.base = 0;
      u_number.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_number.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->number = u_number.real;
      offset += sizeof(this->number);
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
      uint32_t length_full_graph_name;
      arrToVar(length_full_graph_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_full_graph_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_full_graph_name-1]=0;
      this->full_graph_name = (char *)(inbuffer + offset-1);
      offset += length_full_graph_name;
      union {
        int8_t real;
        uint8_t base;
      } u_state;
      u_state.base = 0;
      u_state.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->state = u_state.real;
      offset += sizeof(this->state);
      union {
        int16_t real;
        uint16_t base;
      } u_error_code;
      u_error_code.base = 0;
      u_error_code.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_error_code.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->error_code = u_error_code.real;
      offset += sizeof(this->error_code);
     return offset;
    }

    const char * getType(){ return "cob_script_server/ScriptState"; };
    const char * getMD5(){ return "4981a5a5be8dbf926085d25a1acf43ca"; };

  };

}
#endif