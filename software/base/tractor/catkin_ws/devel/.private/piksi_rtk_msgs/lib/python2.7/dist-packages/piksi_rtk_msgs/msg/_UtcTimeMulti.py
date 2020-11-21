# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from piksi_rtk_msgs/UtcTimeMulti.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import std_msgs.msg

class UtcTimeMulti(genpy.Message):
  _md5sum = "305f41bf5fdb87de324a10b06c47c614"
  _type = "piksi_rtk_msgs/UtcTimeMulti"
  _has_header = True #flag to mark the presence of a Header object
  _full_text = """# This message reports the Universal Coordinated Time (UTC). Note the flags which
# indicate the source of the UTC offset value and source of the time fix.

Header header

uint8 flags   # Indicates source and time validity
uint32 tow    # GPS time of week rounded to the nearest millisecond
uint16 year   # Year
uint8 month   # Month (range 1 .. 12)
uint8 day     # days in the month (range 1-31)
uint8 hours   # hours of day (range 0-23)
uint8 minutes # minutes of hour (range 0-59)
uint8 seconds # seconds of minute (range 0-60) rounded down
uint32 ns     # nanoseconds of second (range 0-999999999)

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id
"""
  __slots__ = ['header','flags','tow','year','month','day','hours','minutes','seconds','ns']
  _slot_types = ['std_msgs/Header','uint8','uint32','uint16','uint8','uint8','uint8','uint8','uint8','uint32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       header,flags,tow,year,month,day,hours,minutes,seconds,ns

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(UtcTimeMulti, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.flags is None:
        self.flags = 0
      if self.tow is None:
        self.tow = 0
      if self.year is None:
        self.year = 0
      if self.month is None:
        self.month = 0
      if self.day is None:
        self.day = 0
      if self.hours is None:
        self.hours = 0
      if self.minutes is None:
        self.minutes = 0
      if self.seconds is None:
        self.seconds = 0
      if self.ns is None:
        self.ns = 0
    else:
      self.header = std_msgs.msg.Header()
      self.flags = 0
      self.tow = 0
      self.year = 0
      self.month = 0
      self.day = 0
      self.hours = 0
      self.minutes = 0
      self.seconds = 0
      self.ns = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_3I().pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_BIH5BI().pack(_x.flags, _x.tow, _x.year, _x.month, _x.day, _x.hours, _x.minutes, _x.seconds, _x.ns))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.header is None:
        self.header = std_msgs.msg.Header()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 16
      (_x.flags, _x.tow, _x.year, _x.month, _x.day, _x.hours, _x.minutes, _x.seconds, _x.ns,) = _get_struct_BIH5BI().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_3I().pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_BIH5BI().pack(_x.flags, _x.tow, _x.year, _x.month, _x.day, _x.hours, _x.minutes, _x.seconds, _x.ns))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.header is None:
        self.header = std_msgs.msg.Header()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 16
      (_x.flags, _x.tow, _x.year, _x.month, _x.day, _x.hours, _x.minutes, _x.seconds, _x.ns,) = _get_struct_BIH5BI().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_3I = None
def _get_struct_3I():
    global _struct_3I
    if _struct_3I is None:
        _struct_3I = struct.Struct("<3I")
    return _struct_3I
_struct_BIH5BI = None
def _get_struct_BIH5BI():
    global _struct_BIH5BI
    if _struct_BIH5BI is None:
        _struct_BIH5BI = struct.Struct("<BIH5BI")
    return _struct_BIH5BI