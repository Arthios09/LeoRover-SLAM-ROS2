# generated from rosidl_generator_py/resource/_idl.py.em
# with input from leo_msgs:srv/SetImuCalibration.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SetImuCalibration_Request(type):
    """Metaclass of message 'SetImuCalibration_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('leo_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'leo_msgs.srv.SetImuCalibration_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_imu_calibration__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_imu_calibration__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_imu_calibration__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_imu_calibration__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_imu_calibration__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetImuCalibration_Request(metaclass=Metaclass_SetImuCalibration_Request):
    """Message class 'SetImuCalibration_Request'."""

    __slots__ = [
        '_gyro_bias_x',
        '_gyro_bias_y',
        '_gyro_bias_z',
    ]

    _fields_and_field_types = {
        'gyro_bias_x': 'double',
        'gyro_bias_y': 'double',
        'gyro_bias_z': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.gyro_bias_x = kwargs.get('gyro_bias_x', float())
        self.gyro_bias_y = kwargs.get('gyro_bias_y', float())
        self.gyro_bias_z = kwargs.get('gyro_bias_z', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.gyro_bias_x != other.gyro_bias_x:
            return False
        if self.gyro_bias_y != other.gyro_bias_y:
            return False
        if self.gyro_bias_z != other.gyro_bias_z:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def gyro_bias_x(self):
        """Message field 'gyro_bias_x'."""
        return self._gyro_bias_x

    @gyro_bias_x.setter
    def gyro_bias_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'gyro_bias_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'gyro_bias_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._gyro_bias_x = value

    @builtins.property
    def gyro_bias_y(self):
        """Message field 'gyro_bias_y'."""
        return self._gyro_bias_y

    @gyro_bias_y.setter
    def gyro_bias_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'gyro_bias_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'gyro_bias_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._gyro_bias_y = value

    @builtins.property
    def gyro_bias_z(self):
        """Message field 'gyro_bias_z'."""
        return self._gyro_bias_z

    @gyro_bias_z.setter
    def gyro_bias_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'gyro_bias_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'gyro_bias_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._gyro_bias_z = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SetImuCalibration_Response(type):
    """Metaclass of message 'SetImuCalibration_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('leo_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'leo_msgs.srv.SetImuCalibration_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_imu_calibration__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_imu_calibration__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_imu_calibration__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_imu_calibration__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_imu_calibration__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetImuCalibration_Response(metaclass=Metaclass_SetImuCalibration_Response):
    """Message class 'SetImuCalibration_Response'."""

    __slots__ = [
        '_success',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.success != other.success:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value


class Metaclass_SetImuCalibration(type):
    """Metaclass of service 'SetImuCalibration'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('leo_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'leo_msgs.srv.SetImuCalibration')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__set_imu_calibration

            from leo_msgs.srv import _set_imu_calibration
            if _set_imu_calibration.Metaclass_SetImuCalibration_Request._TYPE_SUPPORT is None:
                _set_imu_calibration.Metaclass_SetImuCalibration_Request.__import_type_support__()
            if _set_imu_calibration.Metaclass_SetImuCalibration_Response._TYPE_SUPPORT is None:
                _set_imu_calibration.Metaclass_SetImuCalibration_Response.__import_type_support__()


class SetImuCalibration(metaclass=Metaclass_SetImuCalibration):
    from leo_msgs.srv._set_imu_calibration import SetImuCalibration_Request as Request
    from leo_msgs.srv._set_imu_calibration import SetImuCalibration_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
