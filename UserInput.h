#ifndef USERINPUT_H
#define USERINPUT_H

#include <string>

///	<summary>
/// The system commands class is a mix of quality of life system functions,
/// like recurring menu printing, message printing, etc.
/// As well as a place for any validation functions like user input.
/// </summary>
namespace UserInput
{
	/// <summary>
	/// Display a message to the console.
	/// </summary>
	/// <param name="msg"></param>
	void printMsg(const std::string& msg);

	/// <summary>
	/// Prints the programs command menu to the console, expects user input to follow.
	/// </summary>
	void printCommandMenu();


	////// HELPER FUNCTIONS //////
	
	/// <summary>
	/// Helper function to convert a string to all lowercase letters.
	/// Changes the argument passed to it and returns bool based on if it was successful.
	/// </summary>
	/// <param name="str"></param>
	std::string toLower(const std::string& str);

	/// <summary>
	/// Helper function to clear cin buffer
	/// </summary>
	void ignoreLine();


	////// INPUT VALIDATION //////

	/// <summary>
	/// This method acts as a catch all for handling failed user input.
	/// <para>Returns true if extraction failed -- false otherwise.</para>
	/// </summary>
	/// <returns></returns>
	bool clearFailedExtraction();


	std::string getUserInput();
};

#endif