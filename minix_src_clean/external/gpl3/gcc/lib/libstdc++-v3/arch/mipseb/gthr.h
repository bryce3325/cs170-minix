/* This file is automatically generated.  DO NOT EDIT! */
/* Generated from: 	NetBSD: mknative-gcc,v 1.59 2011/07/03 06:47:12 mrg Exp  */
/* Generated from: NetBSD: mknative.common,v 1.9 2007/02/05 18:26:01 apb Exp  */

/* Threads compatibility routines for libgcc2.  */
/* Compile this one with gcc.  */
/* Copyright (C) 1997, 1998, 2004, 2008, 2009 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

#ifndef _GLIBCXX_GCC_GTHR_H
#define _GLIBCXX_GCC_GTHR_H

#ifndef _GLIBCXX_HIDE_EXPORTS
#pragma GCC visibility push(default)
#endif

/* If this file is compiled with threads support, it must
       #define __GTHREADS 1
   to indicate that threads support is present.  Also it has define
   function
     int __gthread_active_p ()
   that returns 1 if thread system is active, 0 if not.

   The threads interface must define the following types:
     __gthread_key_t
     __gthread_once_t
     __gthread_mutex_t
     __gthread_recursive_mutex_t

   The threads interface must define the following macros:

     __GTHREAD_ONCE_INIT
     		to initialize __gthread_once_t
     __GTHREAD_MUTEX_INIT
     		to initialize __gthread_mutex_t to get a fast
		non-recursive mutex.
     __GTHREAD_MUTEX_INIT_FUNCTION
     		some systems can't initialize a mutex without a
		function call.  On such systems, define this to a
		function which looks like this:
		  void __GTHREAD_MUTEX_INIT_FUNCTION (__gthread_mutex_t *)
		Don't define __GTHREAD_MUTEX_INIT in this case
     __GTHREAD_RECURSIVE_MUTEX_INIT
     __GTHREAD_RECURSIVE_MUTEX_INIT_FUNCTION
     		as above, but for a recursive mutex.

   The threads interface must define the following static functions:

     int __gthread_once (__gthread_once_t *once, void (*func) ())

     int __gthread_key_create (__gthread_key_t *keyp, void (*dtor) (void *))
     int __gthread_key_delete (__gthread_key_t key)

     void *__gthread_getspecific (__gthread_key_t key)
     int __gthread_setspecific (__gthread_key_t key, const void *ptr)

     int __gthread_mutex_destroy (__gthread_mutex_t *mutex);

     int __gthread_mutex_lock (__gthread_mutex_t *mutex);
     int __gthread_mutex_trylock (__gthread_mutex_t *mutex);
     int __gthread_mutex_unlock (__gthread_mutex_t *mutex);

     int __gthread_recursive_mutex_lock (__gthread_recursive_mutex_t *mutex);
     int __gthread_recursive_mutex_trylock (__gthread_recursive_mutex_t *mutex);
     int __gthread_recursive_mutex_unlock (__gthread_recursive_mutex_t *mutex);

   The following are supported in POSIX threads only. They are required to
   fix a deadlock in static initialization inside libsupc++. The header file
   gthr-posix.h defines a symbol __GTHREAD_HAS_COND to signify that these extra
   features are supported.

   Types:
     __gthread_cond_t

   Macros:
     __GTHREAD_COND_INIT
     __GTHREAD_COND_INIT_FUNCTION

   Interface:
     int __gthread_cond_broadcast (__gthread_cond_t *cond);
     int __gthread_cond_wait (__gthread_cond_t *cond, __gthread_mutex_t *mutex);
     int __gthread_cond_wait_recursive (__gthread_cond_t *cond,
					__gthread_recursive_mutex_t *mutex);

   All functions returning int should return zero on success or the error
   number.  If the operation is not supported, -1 is returned.

   If the following are also defined, you should
     #define __GTHREADS_CXX0X 1
   to enable the c++0x thread library.

   Types:
     __gthread_t
     __gthread_time_t

   Interface:
     int __gthread_create (__gthread_t *thread, void *(*func) (void*),
                           void *args);
     int __gthread_join (__gthread_t thread, void **value_ptr);
     int __gthread_detach (__gthread_t thread);
     int __gthread_equal (__gthread_t t1, __gthread_t t2);
     __gthread_t __gthread_self (void);
     int __gthread_yield (void);

     int __gthread_mutex_timedlock (__gthread_mutex_t *m,
                                    const __gthread_time_t *abs_timeout);
     int __gthread_recursive_mutex_timedlock (__gthread_recursive_mutex_t *m,
                                          const __gthread_time_t *abs_time);

     int __gthread_cond_signal (__gthread_cond_t *cond);
     int __gthread_cond_timedwait (__gthread_cond_t *cond,
                                   __gthread_mutex_t *mutex,
                                   const __gthread_time_t *abs_timeout);
     int __gthread_cond_timedwait_recursive (__gthread_cond_t *cond,
                                             __gthread_recursive_mutex_t *mutex,
                                             const __gthread_time_t *abs_time)

   Currently supported threads packages are
     TPF threads with -D__tpf__
     POSIX/Unix98 threads with -D_PTHREADS
     POSIX/Unix95 threads with -D_PTHREADS95
     DCE threads with -D_DCE_THREADS
     Solaris/UI threads with -D_SOLARIS_THREADS

*/

/* Check first for thread specific defines.  */
#if defined (_GLIBCXX___tpf_GLIBCXX___)
#include <bits/gthr-tpf.h>
#elif _GLIBCXX__PTHREADS
#include <bits/gthr-posix.h>
#elif _GLIBCXX__PTHREADS95
#include <bits/gthr-posix95.h>
#elif _GLIBCXX__DCE_THREADS
#include <bits/gthr-dce.h>
#elif _GLIBCXX__SOLARIS_THREADS
#include <bits/gthr-solaris.h>

/* Include GTHREAD_FILE if one is defined.  */
#elif defined(_GLIBCXX_HAVE_GTHR_DEFAULT)
#if __GXX_WEAK__
#ifndef _GLIBCXX_GTHREAD_USE_WEAK
#define _GLIBCXX_GTHREAD_USE_WEAK 1
#endif
#endif
#include <bits/gthr-default.h>

/* Fallback to single thread definitions.  */
#else
#include <bits/gthr-single.h>
#endif

#ifndef _GLIBCXX_HIDE_EXPORTS
#pragma GCC visibility pop
#endif

#endif /* ! _GLIBCXX_GCC_GTHR_H */
