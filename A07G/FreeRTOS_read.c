static void FreeRTOS_read(char *character)
{
	// Suspend the task until data is available.
	vTaskSuspend(NULL);  // The task will be suspended until another task calls vTaskResume().
	
	// Wait until a new character is available in the circular buffer.
	if (xSemaphoreTake(xReadSemaphore, portMAX_DELAY) == pdTRUE)
	{
		// Attempt to retrieve a character from the circular buffer.
		if (circular_buf_get(circularBuffer, (uint8_t *)character) != 0)
		{
			// If no character is retrieved, set the output to null character.
			*character = '\0';
		}
	}
}