#ifndef _ROS_SERVICE_ImportTrajectory_h
#define _ROS_SERVICE_ImportTrajectory_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ram_utils
{

static const char IMPORTTRAJECTORY[] = "ram_utils/ImportTrajectory";

  class ImportTrajectoryRequest : public ros::Msg
  {
    public:
      typedef const char* _file_name_type;
      _file_name_type file_name;

    ImportTrajectoryRequest():
      file_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_file_name = strlen(this->file_name);
      varToArr(outbuffer + offset, length_file_name);
      offset += 4;
      memcpy(outbuffer + offset, this->file_name, length_file_name);
      offset += length_file_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_file_name;
      arrToVar(length_file_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_file_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_file_name-1]=0;
      this->file_name = (char *)(inbuffer + offset-1);
      offset += length_file_name;
     return offset;
    }

    const char * getType(){ return IMPORTTRAJECTORY; };
    const char * getMD5(){ return "2415261c9605b9f38867ffbbe495fc04"; };

  };

  class ImportTrajectoryResponse : public ros::Msg
  {
    public:
      typedef const char* _error_type;
      _error_type error;

    ImportTrajectoryResponse():
      error("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_error = strlen(this->error);
      varToArr(outbuffer + offset, length_error);
      offset += 4;
      memcpy(outbuffer + offset, this->error, length_error);
      offset += length_error;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_error;
      arrToVar(length_error, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_error; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_error-1]=0;
      this->error = (char *)(inbuffer + offset-1);
      offset += length_error;
     return offset;
    }

    const char * getType(){ return IMPORTTRAJECTORY; };
    const char * getMD5(){ return "eca8b96616c32aacf1be8bbf14c70eba"; };

  };

  class ImportTrajectory {
    public:
    typedef ImportTrajectoryRequest Request;
    typedef ImportTrajectoryResponse Response;
  };

}
#endif
