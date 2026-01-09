#pragma once

#include <cstdint>
#include <string>

/**
 * @brief Supported controller types for virtual gamepad emulation.
 *
 * These map to real controller VID/PID pairs that games recognize.
 */
enum class ControllerType
{
	Xbox360,		 // Microsoft Xbox 360 Controller (default)
	XboxOne,		 // Microsoft Xbox One Controller
	DualShock4,		 // Sony DualShock 4
	DualSense,		 // Sony DualSense (PS5)
	SwitchPro,		 // Nintendo Switch Pro Controller
	Generic			 // Generic gamepad (no specific VID/PID)
};

/**
 * @brief Controller identification info (VID/PID pair).
 */
struct ControllerInfo
{
	uint16_t vendorId;
	uint16_t productId;
	const char *name;
	const char *shortName;
};

/**
 * @brief Get controller info for a given type.
 * @param type The controller type.
 * @return ControllerInfo struct with VID/PID and name.
 */
inline ControllerInfo getControllerInfo(ControllerType type)
{
	switch (type)
	{
	case ControllerType::Xbox360:
		return {0x045E, 0x028E, "Xbox 360 Controller", "xbox360"};
	case ControllerType::XboxOne:
		return {0x045E, 0x02D1, "Xbox One Controller", "xboxone"};
	case ControllerType::DualShock4:
		return {0x054C, 0x05C4, "DualShock 4", "ds4"};
	case ControllerType::DualSense:
		return {0x054C, 0x0CE6, "DualSense", "dualsense"};
	case ControllerType::SwitchPro:
		return {0x057E, 0x2009, "Switch Pro Controller", "switchpro"};
	case ControllerType::Generic:
	default:
		return {0x0000, 0x0000, "Generic Gamepad", "generic"};
	}
}

/**
 * @brief Parse controller type from string.
 * @param name String name (e.g., "xbox360", "ds4", "dualsense").
 * @return ControllerType enum value, defaults to Xbox360.
 */
inline ControllerType parseControllerType(const std::string &name)
{
	if (name == "xbox360" || name == "Xbox360")
		return ControllerType::Xbox360;
	if (name == "xboxone" || name == "XboxOne")
		return ControllerType::XboxOne;
	if (name == "ds4" || name == "DualShock4" || name == "dualshock4")
		return ControllerType::DualShock4;
	if (name == "dualsense" || name == "DualSense")
		return ControllerType::DualSense;
	if (name == "switchpro" || name == "SwitchPro")
		return ControllerType::SwitchPro;
	if (name == "generic" || name == "Generic")
		return ControllerType::Generic;
	return ControllerType::Xbox360; // Default
}
