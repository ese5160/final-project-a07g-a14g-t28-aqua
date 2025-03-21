/**************************************************************************/
/**
 * @file        SerialConsole.h
 * @ingroup 	Serial Console
 * @brief       This file has the code necessary to run the CLI and Serial Debugger. 
 * 				It initializes an UART channel and uses it to receive command from the user
 *				as well as print debug information.
 * @details     This file has the code necessary to run the CLI and Serial Debugger. 
 * 				It initializes an UART channel and uses it to receive command from the user
 *				as well as print debug information.
 *
 *				The code in this file will:
 *				--Initialize a SERCOM port (SERCOM # ) to be an UART channel operating at 115200 baud/second, 8N1
 *				--Register callbacks for the device to read and write characters asycnhronously as required by the CLI
 *				--Initialize the CLI and Debug Logger datastructures
 *
 *				Usage:
 *
 *
 * @copyright
 * @author
 * @date        January 26, 2019
 * @version		0.1
 *****************************************************************************/

 #ifndef SERIAL_CONSOLE_H
 #define SERIAL_CONSOLE_H
 
 /******************************************************************************
  * Includes
  ******************************************************************************/
 #include <asf.h>
 #include <string.h>
 #include <stdarg.h>
 #include "circular_buffer.h"
 


/******************************************************************************
* Global Function Declarations
******************************************************************************/
/**
 * @fn			void InitializeSerialConsole(void)
 * @brief		Initializes the UART - sets up the SERCOM to act as UART and registers the callbacks for
 *				asynchronous reads and writes.
 * @details		Initializes the UART - sets up the SERCOM to act as UART and registers the callbacks for
 *				asynchronous reads and writes.
 * @note			Call from main once to initialize Hardware.
 *****************************************************************************/
void InitializeSerialConsole(void);

/**************************************************************************/
/**
 * @fn			void DeinitializeSerialConsole(void)
 * @brief		Deinitlaises the UART
 * @note
 *****************************************************************************/
void DeinitializeSerialConsole(void);

/**
 * @fn			void SerialConsoleWriteString(char * string)
 * @brief		Writes a string to be written to the uart. Copies the string to a ring buffer that 
 * 				is used to hold the text send to the uart
 * @details		Uses the ringbuffer 'cbufTx', which in turn uses the array 'txCharacterBuffer'
 * @note			Use to send a string of characters to the user via UART
 *****************************************************************************/
void SerialConsoleWriteString(char * string);

/**
 * @fn			int SerialConsoleReadCharacter(uint8_t *rxChar)
 * @brief		Reads a character from the RX ring buffer and stores it on the pointer given as an argument.
 *				Also, returns -1 if there is no characters on the buffer
 *				This buffer has values added to it when the UART receives ASCII characters from the terminal
 * @details		Uses the ringbuffer 'cbufTx', which in turn uses the array 'txCharacterBuffer'
 * @param[in]	Pointer to a character. This function will return the character from the RX buffer into this pointer
 * @return		Returns -1 if there are no characters in the buffer
 * @note			Use to receive characters from the RX buffer (FIFO)
 *****************************************************************************/
int SerialConsoleReadCharacter(uint8_t *rxChar);




/******************************************************************************
* Local Functions
******************************************************************************/


#endif /* SERIAL_CONSOLE_H */
