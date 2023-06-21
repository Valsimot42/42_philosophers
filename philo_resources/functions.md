# == FUNCTIONS ==

# --gettimeofday--

This function is used to retrieve the current time and store it in a "struct timeval" object.
It is typically used for measuring time intervals or benchmarking code.

Prototype of the function:

# int gettimeofday(struct timeval *tv, struct timezone *tz);

The function takes two parameters: a pointer to a 'struct timeval' object (tv) and a pointer to
a 'struct timezone' object (tz). The 'struct timeval' object is used to store the current time,
while the 'struct timezone' object is used to store information about the time zone. However,
it is important to note that the 'struct timezone' parameter is obsolete and has no effect on
modern systems, so you can pass 'NULL' for this parameter.

The 'struct timeval' structure has the following definition:

# struct timeval {
#     time_t      tv_sec;     // seconds
#     suseconds_t tv_usec;    // microseconds
# };

The 'tv_sec' member represents the number of seconds since the epock (usually January 1, 1970).
The 'tv_usec' member represents the additional microseconds that have elapsed.

After calling 'gettimeofday', the current time is stored in the 'tv' object, allowing you to
access the time values for further processing or calculations.

Example usage of 'gettimeofday':

# #include <stdio.h>
# #include <sys/time.h>

# int main() {
#     struct timeval tv;
#     if (gettimeofday(&tv, NULL) == 0) {
#         printf("Seconds: %ld\n", tv.tv_sec);
#         printf("Microseconds: %ld\n", tv.tv_usec);
#     } else {
#         printf("Error occurred while getting time.\n");
#    }
#   
#     return 0;
# }

This example retrieves the current time using 'gettimeofday' and prints the seconds and
microseconds to the console. Note that error checking is important, as the function may fail in
certain circumstances.

# -- END --

# -- pthread_create --

The 'pthread_create' function is used to create a new thread. It allows concurrent execution of
multiple threads within a program.

Prototype of the function:

# #include <pthread.h>

# int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
#                    void *(*start_routine)(void *), void *arg);

The 'pthread_create' function takes four parameters:

1)	'thread': A pointer to a 'pthread_t' object that will be used to identify the newly created
	thread.

2)	'attr': A pointer to a 'pthread_attr_t' object that specifies the attributes for the new
	thread. You can pass 'NULL' to use the default attributes.

3)	'start_routine': A function pointer to the function that will be executed by the new thread.
	The function must have the following signature: 'void *function_name(void *)'. It takes a
	single argument (of type 'void*') and returns a 'void*' pointer.

4)	'arg': An argument that will be passed on to the 'start_routine' function when it is
	invoked. It can be used to pass data or parameteres to the thread function.

When 'pthread_create' is called, a new thread is created, and the execution of that thread
starts by calling the 'start_routine' function with the 'arg' parameter. The 'start_routine'
function can perform any operations or computations within the thread.

Example usage of 'pthread_create':

# #include <stdio.h>
# #include <pthread.h>

# void *thread_function(void *arg) {
#     int thread_id = *(int *)arg;
#     printf("Hello from thread %d!\n", thread_id);
#    pthread_exit(NULL);
# }

# int main() {
#     pthread_t thread;
#     int thread_id = 1;

#     if (pthread_create(&thread, NULL, thread_function, (void *)&thread_id) != 0) {
#         fprintf(stderr, "Failed to create thread.\n");
#         return 1;
#     }

#     // Wait for the created thread to finish
#     pthread_join(thread, NULL);

#     printf("Main thread exiting.\n");
#     return 0;
# }

In this example, 'pthread_create' is used to create a new thread that executes the
'thread_function'. The 'thread_id' variable is passed as an argument to the thread function. The
main thread waits for the created thread to finish using 'pthread_join' before it exists.

Upon execution, this should be the output:

# Hello from thread 1!
# Main thread exiting.

Note that error checking is important when using 'pthread_create'. If the function fails, it
returns a non-zero value, indicating an error in thread creation.

# -- END --

# -- pthread_detach --

The 'pthread_detach' function allows you to mark a thread as detached. A detached thread can
continue its execution independently, and its resources will be automatically released when it
finishes.

Prototype of the function:

# #include <pthread.h>

# int pthread_detach(pthread_t thread);

The 'pthread_detach' function takes a single parameter:

1)	'thread': The thread identifier ('pthread_t') of the thread that you want to detach.

By calling 'pthread_detach' on a thread, you indicate that you are no longer interested in
collecting the exit status of the thread using 'pthread_join'. The resources associated with
the thread will be released automarically when it finishes execution.

Example usage of 'pthread_detach':

# #include <stdio.h>
# #include <pthread.h>

# void *thread_function(void *arg) {
#     printf("Thread executing.\n");
#     pthread_exit(NULL);
# }

# int main() {
#     pthread_t thread;

#     if (pthread_create(&thread, NULL, thread_function, NULL) != 0) {
#         fprintf(stderr, "Failed to create thread.\n");
#         return 1;
#     }

#     if (pthread_detach(thread) != 0) {
#         fprintf(stderr, "Failed to detach thread.\n");
#         return 1;
#     }

#     printf("Main thread exiting.\n");
#     return 0;
# }

In this example, 'pthread_create' is used to create a new thread that executes the
'thread_function'. After creating the thread, 'pthread_detach' is called to detach the thread.
The main thread does not wait for the detached thread to finish; it simply continues execution
and eventually exits.

It's important to note that once a thread is detached, you cannot join or collect its exit
status using 'pthread_join'. If you attempt to join a detached thread, it will result in an
error.

Detaching a thread can be useful when you don't need to wait for its completion or retrieve its
exit status. It allows the thread to run independently, and the system will take care of
releasing its resources automatically when it finishes. However, it's important to ensure
that the resources accessed by the detached thread are properly managed to prevent resource
leaks or undefined behavior.

# -- END --

# -- pthread_join --

This function is used to wait for a thread to finish its execution and retrieve its exit
status.

Protype of the function:

# #include <pthread.h>

# int pthread_join(pthread_t thread, void **value_ptr);

The 'pthread_join' function takes two parameteres:

1)	'thread': The thread identifier ('pthread_t') of the thread that you want to join.

2)	'vaule_ptr': A pointer to a 'void*' variable where the exit status of the joined thread
	stored.

When you call 'pthread_join' on a thread, the calling thread will be blocked until the
specified thread completes its execution. If the target thread has already finished,
'pthread_join' returns immediately.

Upon successful completion of 'pthread_join', the exit status of the joined thread is stored
in the 'value_ptr' variable. This exit status is set by the thread when it calls
'pthread_exit' or returns from the thread function.

Example usage of 'pthread_join':

# #include <stdio.h>
# #include <pthread.h>

# void *thread_function(void *arg) {
#     printf("Thread executing.\n");
#     pthread_exit((void *)42);
# }

# int main() {
#     pthread_t thread;
#     void *exit_status;

#     if (pthread_create(&thread, NULL, thread_function, NULL) != 0) {
#         fprintf(stderr, "Failed to create thread.\n");
#        return 1;
#    }

#    if (pthread_join(thread, &exit_status) != 0) {
#        fprintf(stderr, "Failed to join thread.\n");
#        return 1;
#    }
#
#    printf("Joined thread with exit status: %ld\n", (long)exit_status);

#    printf("Main thread exiting.\n");
#    return 0;
# }

In this example, 'pthread_create' is used to create a new thread that executes the
'thread_function'. After creating the thread, 'pthread_join' is called to wait for the thread
to finish its execution. The exit status of the joined thread is stored in the 'exit_status'
variable.

Once 'pthread_join' returns, you can access the exit status and perform further processing or
error handling based on the result.

It's important to note that 'pthread_join' allows you to synchronize the execution of multiple
threads, ensuring that the main thread waits for the completion of the joined thread before
continuing its exectuion.

If you don't need to wait for a thread to retrieve its exist status, you can detach the thread
using 'pthread_detach' instead of joining it.

Remember to handle errors appropriately and check the return values of 'pthread_create' and
'pthread_join' for any potential failures.

# -- END --

# -- pthread_mutex_init --

This function is used to initialize a mutex object. It allows for thread synchronization
by providing mutual exclusion.

Prototype of the function:

# #include <pthread.h>

# int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);

The 'pthread_mutex_init' function takes two parameters:

1)	'mutex': A pointer to a 'pthread_mutex_t' object that will be initialized.

2)	'attr': A pointer to a 'pthread_mutexattr_t' object that specifies the attributes for the
	mutex. You can pass 'NULL' to use the default attributes.

Before you can use a mutex for synchronization, it needs to be initialized using
'pthread_mutex_init'. This function sets up the mutex object, preparing it for subsequent
locking and unlocking operations.

Example usage of 'pthread_mutex_init':

# #include <stdio.h>
# #include <pthread.h>

# int main() {
#     pthread_mutex_t mutex;
 
#     if (pthread_mutex_init(&mutex, NULL) != 0) {
#         fprintf(stderr, "Failed to initialize mutex.\n");
#         return 1;
#     }
 
#     // Use the mutex for synchronization
 
#     pthread_mutex_destroy(&mutex);
 
#     printf("Mutex destroyed.\n");
#     return 0;
# }

In this example, 'pthread_mutex_init' is called to initialize a mutex object named 'mutex'. The
second parameter is set to 'NULL' to use the default attributes. After initialization, the
mutex can be used for synchronization.

Once you're done using the mutex, you should call 'pthread_mutex_destroy' to release the
associated resources. It is important to destroy the mutex when you no longer need it to avoid
resource leaks.

Note that 'pthread_mutex_init' can fail if there is insufficient memory to create the mutex or
if an invalid attribute object is specified. It's good practice to check the return value of
'pthread_mutex_init' for any potential errors.

Mutexes are commonly used to protect critical sections of code from concurrent access by
multiple threads. They allow only one thread to enter the critical section at a time, ensuring
mutual exclusion and preventing race conditions.

Remember to use locking and unlocking operations ('pthread_mutex_lock' and
'pthread_mutex_unlock) to properly control access to the critical section while using the
initialized mutex.

# -- END --

# -- pthread_mutex_destroy --

This function is used to destroy a mutex object, and to release the resources associated
with a mutex that is no longer needed.

Prototype of the function:

# #include <pthread.h>

# int pthread_mutex_destroy(pthread_mutex_t *mutex);

The 'pthread_mutex_destroy' function takes a single parameter:

1)	'mutex': A pointer to the mutex object ('pthread_mutex_t') that you want to destroy.

When you call 'pthread_mutex_destroy' on a mutex, it releases any resources associated with
the mutex, including system resources. After destroying the mutex, you should not use it
again without reinitializing it using 'pthread_mutex_init'.

Example usage of 'pthread_mutex_destroy'.

# #include <stdio.h>
# #include <pthread.h>

# int main() {
#     pthread_mutex_t mutex;

#     if (pthread_mutex_init(&mutex, NULL) != 0) {
#         fprintf(stderr, "Failed to initialize mutex.\n");
#         return 1;
#     }

#     // Use the mutex for synchronization

#     pthread_mutex_destroy(&mutex);

#     printf("Mutex destroyed.\n");
#     return 0;
# }

In this example, 'pthread_mutex_init' is called to initialize a mutex object named 'mutex'.
After using the mutex for syncrhonization purposes, 'pthread_mutex_destroy' is called to release
the associated resources.

It's important to note that you should only call 'pthread_mutex_destroy' when yu are certain
that the mutex is no longer needed and no threads are currently using it. If a thread attemtps
to lock or unlock a destroyed mutex, it results in undefined behavior.

Additionally, it's a good practice to destroy all initialized mutexes to avoid resource leaks
and ensure proper cleanup.

Remember that when you destroy a mutex, you should not use it again without reinitializing it
using 'pthread_mutex_init' if you need to use it in the future.

Make sure to handle any errors that may occur during the destruction of the mutex by checking
the return value of 'pthread_mutex_destroy'.

# -- END --

# -- pthread_mutex_lock --

This function is used to acquire a lock on a mutex object, and it is also used for thread
synchronization to provide mutual exclusion.

# #include <pthread.h>

# int pthread_mutex_lock(pthread_mutex_t *mutex);

The 'pthread_mutex_lock' function takes a single parameter:

1)	'mutex': A pointer to the mutex object ('pthread_mutex_t') that you want to lock.

When you call a 'pthread_mutex_lock' on a mutex, it attempts to acquire the lock on the
mutex. If the mutex is currently unlocked, the calling thread acquires the lock and
proceeds to execute the critical section of code protected by the mutex.

If the mutex is already locked by another thread, the calling thread will be blocked until
the mutex becomes available. this blocking behavior ensures that only one thread can execute
the critical section at a time, ensuring mutual exclusion.

Example usage of 'pthread_mutex_lock':

# #include <stdio.h>
# #include <pthread.h>

# pthread_mutex_t mutex;

# void *thread_function(void *arg) {
#     pthread_mutex_lock(&mutex);

#     printf("Thread acquired the lock.\n");

#     // Perform critical section operations

#     pthread_mutex_unlock(&mutex);

#     printf("Thread released the lock.\n");

#     pthread_exit(NULL);
# }

# int main() {
#     pthread_t thread;

#     pthread_mutex_init(&mutex, NULL);

#     if (pthread_create(&thread, NULL, thread_function, NULL) != 0) {
#         fprintf(stderr, "Failed to create thread.\n");
#         return 1;
#     }

#     pthread_mutex_lock(&mutex);

#     printf("Main thread acquired the lock.\n");

#     // Perform critical section operations

#     pthread_mutex_unlock(&mutex);

#     printf("Main thread released the lock.\n");

#     pthread_join(thread, NULL);

#     pthread_mutex_destroy(&mutex);

#     return 0;
# }

In this example, a mutex named 'mutex' is initialized using 'pthread_mutex_init'. The
'pthread_create' function is used to create a new thread that executes the 'thread_function'.
Both the main thread and the created thread attempt to acquire the lock on the mutex using
'pthread_mutex_lock' to execute their respective critical sections. After performing the
critical section operations, they release the lock using 'pthread_mutex_unlock'.

It's important to note that if multiple threads attempt to lock the same mutex
simultaneously, only one thread will successfully acquire the lock, while the others will be
blocked until the lock becomes available.

To ensure proper synchronization and avoid race conditions or deadlocks, make sure that every
'pthread_mutex_lock' call is paired with a corresponding 'pthread_mutex_unlock' call to release
the lock when it is no longer needed.

Remember to handle any potential errors that may occur when acquiring the lock by checking the
return value of 'pthread_mutex_lock'.

# -- END --

# -- pthread_mutex_unlock --

This function is used to release the lock on a mutex object, it is also used for thread
synchronization to provide mutual exclusion.

Prototype of the function:

# #include <pthread.h>

# int pthread_mutex_unlock(pthread_mutex_t *mutex);

The 'pthread_mutex_unlock' function takes a single parameter:

1)	'mutex': A pointer to the mutex object ('pthread_mutex_t') that you want to unlock.

When you call 'pthread_mutex_unlock' on a mutex, it releases the lock that was previously
acquired by the calling thread. This allows other threads that are waiting to acquire the
same mutex to proceed.

Example usage of 'pthread_mutex_unlock':

# #include <stdio.h>
# #include <pthread.h>

# pthread_mutex_t mutex;

# void *thread_function(void *arg) {
#     pthread_mutex_lock(&mutex);

#     printf("Thread acquired the lock.\n");

#     // Perform critical section operations

#     pthread_mutex_unlock(&mutex);

#     printf("Thread released the lock.\n");

#     pthread_exit(NULL);
# }

# int main() {
#     pthread_t thread;

#     pthread_mutex_init(&mutex, NULL);

#     if (pthread_create(&thread, NULL, thread_function, NULL) != 0) {
#         fprintf(stderr, "Failed to create thread.\n");
#         return 1;
#     }

#     pthread_mutex_lock(&mutex);

#     printf("Main thread acquired the lock.\n");

#     // Perform critical section operations

#     pthread_mutex_unlock(&mutex);

#     printf("Main thread released the lock.\n");

#     pthread_join(thread, NULL);

#     pthread_mutex_destroy(&mutex);

#     return 0;
# }

In this example, a mutex named 'mutex' is initialized using 'pthread_mutex_init'. The
'pthread_create' function is used to create a new thread that executes the 'thread_function'.
Both the main thread and the created thread acquire the lock on the mutex using
'pthread_mutex_lock' to execute their respective critical sections. After performing the
critical section operations, they release the lock using 'pthread_mutex_unlock'.

It's important to note that the thread calling 'pthread_mutex_unlock' should be the same
thread that previously acquired the lock using 'pthread_mutex_lock'. Attempting to unlock
a mutex that is locked by another thread results in udnefined behavior.

To ensure proper synchronization and avoid race conditions or deadlocks, make sure that
every 'pthread_mutex_lock' call is paired with a corresponding 'pthread_mutex_unlock' call
to release the lock when it is no longer needed.

Remember to handle any potentinal errors that may occur when releasing the lock by checking
the return value of 'pthread_mutex_unlock'.

# -- END --