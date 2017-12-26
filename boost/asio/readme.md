https://www.gamedev.net/blogs/entry/2249317-a-guide-to-getting-started-with-boostasio/


 To get the io_service working for us, we have to use the run or poll family of functions. Run will block and wait for work if we assign it a work object while the poll function does not. In essence, the names of the functions match their functionality


use the shared pointer for the work class for ioservice.

What should really stand out is how simple and easy it is to make our threaded programs scale. By simply adding more worker threads, we can support more and more concurrency for processing work through the io_service object.

the io_service object is non-copyable, so to make use of it, you can create a sharepointer and pass it along.

To further clarify once again if we are using the io_service for user work, we have to use exception handling if the work can generate exceptions. If we are using the io_service for boost::asio functions only, then we can use exception handling or the error variable as either will do.
 If we are using the io_service for both boost::asio functions and user work, then we can either use both methods or just the exception handling method, but not only the error variable if the work can generate an exception. That should be pretty straightforward to follow.

