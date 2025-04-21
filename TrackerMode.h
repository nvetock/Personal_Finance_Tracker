#ifndef TRACKERMODE_H
#define TRACKERMODE_H

#include <string>

namespace TrackerMode {
	enum Mode {
		UNSET,
		VIEW,
		MODIFY,
	};

	/// <summary>
	/// Converts a MODE enum to string.
	/// </summary>
	/// <param name="mode"></param>
	/// <returns></returns>
	const std::string convertModeToString(Mode mode);
	
	/// <summary>
	/// Converts a string to a MODE enum.
	/// </summary>
	/// <param name="str"></param>
	/// <returns></returns>
	const Mode convertStringToMode(std::string str);
}

#endif