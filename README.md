# STD-Mutex
The mutex class is a synchronization primitive that can be used to protect shared data from being simultaneously accessed by multiple threads.  Added since C++ 11.
mutex offers exclusive, non-recursive ownership semantics:

    A calling thread owns a mutex from the time that it successfully calls either lock or try_lock until it calls unlock.
    When a thread owns a mutex, all other threads will block (for calls to lock) or receive a false return value (for try_lock) if they attempt to claim ownership of the mutex.
    A calling thread must not own the mutex prior to calling lock or try_lock. 

The behavior of a program is undefined if a mutex is destroyed while still owned by any threads, or a thread terminates while owning a mutex. The mutex class satisfies all requirements of Mutex and StandardLayoutType.

std::mutex is neither copyable nor movable. 

Member types
Member type 	Definition
native_handle_type(optional) 	implementation-defined
Member functions
(constructor)
	constructs the mutex
(public member function)
(destructor)
	destroys the mutex
(public member function)
operator=
[deleted]
	not copy-assignable
(public member function)
Locking
lock
	locks the mutex, blocks if the mutex is not available
(public member function)
try_lock
	tries to lock the mutex, returns if the mutex is not available
(public member function)
unlock
	unlocks the mutex
(public member function)
Native handle
native_handle
	returns the underlying implementation-defined native handle object
(public member function)
Notes

std::mutex is usually not accessed directly: std::unique_lock, std::lock_guard, or std::scoped_lock (since C++17) manage locking in a more exception-safe manner. 
