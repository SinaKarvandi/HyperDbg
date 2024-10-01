/**
 * @file hw_clk.cpp
 * @author Sina Karvandi (sina@hyperdbg.org)
 * @brief !hw_clk command
 * @details
 * @version 0.9
 * @date 2024-05-29
 *
 * @copyright This project is released under the GNU Public License v3.
 *
 */
#include "pch.h"

//
// Global Variables
//
extern HWDBG_INSTANCE_INFORMATION g_HwdbgInstanceInfo;

/**
 * @brief help of the !hw command
 *
 * @return VOID
 */
VOID
CommandHwHelp()
{
    ShowMessages("!hw : runs a hardware script in the target device.\n\n");

    ShowMessages("syntax : \t!hw script [script { Script (string) }]\n");

    ShowMessages("\n");
    ShowMessages("\t\te.g : !hw script { @hw_pin1 = 0; }\n");
}

/**
 * @brief !hw command handler
 *
 * @param CommandTokens
 * @param Command
 *
 * @return VOID
 */
VOID
CommandHw(vector<CommandToken> CommandTokens, string Command)
{
    if (CommandTokens.size() >= 2 && CompareLowerCaseStrings(CommandTokens.at(1), "script"))
    {
        //
        // Perform test with default file path and initial BRAM buffer size
        //
        HwdbgScriptRunScript(GetCaseSensitiveStringFromCommandToken(CommandTokens.at(2)).c_str(),
                             HWDBG_TEST_READ_INSTANCE_INFO_PATH,
                             HWDBG_TEST_WRITE_SCRIPT_BUFFER_PATH,
                             DEFAULT_INITIAL_BRAM_BUFFER_SIZE);
    }
    else
    {
        ShowMessages("incorrect use of the '%s'\n\n",
                     GetCaseSensitiveStringFromCommandToken(CommandTokens.at(0)).c_str());
        CommandHwHelp();
        return;
    }
}
