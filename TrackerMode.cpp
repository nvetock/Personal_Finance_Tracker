#include "TrackerMode.h"

const std::string TrackerMode::convertModeToString(TrackerMode::Mode mode) {
	switch (mode) {
	case TrackerMode::UNKNOWN:   return "UNKNOWN";
	case TrackerMode::VIEW:      return "VIEW";
	case TrackerMode::MODIFY:    return "MODIFY";
	default:                     return "UNKNOWN";
	}
}

const TrackerMode::Mode TrackerMode::convertStringToMode(std::string str) {
	for (int i = 0; i < str.size(); ++i) {
		str[i] = std::toupper(str[i]);
	}
	
	if (str == "VIEW")           return TrackerMode::Mode::VIEW;
	else if (str == "MODIFY")    return TrackerMode::Mode::MODIFY;
	else                         return TrackerMode::Mode::UNKNOWN;
}