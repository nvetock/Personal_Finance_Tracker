#ifndef FINTRACKER_H
#define FINTRACKER_H

#include "TrackerMode.h"

/// <summary>
/// FinTracker is the brain that passes user intention to the correct object that will handle the desired operations.
/// </summary>
class FinTracker
{
public:
	FinTracker(TrackerMode::Mode mode)
		: _trackerMode{ mode }
	{ }



	const TrackerMode::Mode getMode() const;
	void setMode(std::string& input);

private:
	TrackerMode::Mode _trackerMode{ TrackerMode::Mode::UNSET };
};

#endif