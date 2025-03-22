void usart_read_callback(struct usart_module *const usart_module)
{
	// Simply put the received character into the circular buffer
	circular_buf_put(cbufRx, (uint8_t)latestRx); // No need to check return value

	// Restart the read job to continue receiving characters
	usart_read_buffer_job(&usart_instance, (uint8_t *)&latestRx, 1);
}