/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2013 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_MYFILE_H
#define PHP_MYFILE_H

extern zend_module_entry myfile_module_entry;
#define phpext_myfile_ptr &myfile_module_entry

#ifdef PHP_WIN32
#	define PHP_MYFILE_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_MYFILE_API __attribute__ ((visibility("default")))
#else
#	define PHP_MYFILE_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(myfile);
PHP_MSHUTDOWN_FUNCTION(myfile);
PHP_RINIT_FUNCTION(myfile);
PHP_RSHUTDOWN_FUNCTION(myfile);
PHP_MINFO_FUNCTION(myfile);

PHP_FUNCTION(confirm_myfile_compiled);	/* For testing, remove later. */
PHP_FUNCTION(file_open);
PHP_FUNCTION(file_close);
PHP_FUNCTION(file_read);
PHP_FUNCTION(file_write);
PHP_FUNCTION(file_eof);

/* 
  	Declare any global variables you may need between the BEGIN
	and END macros here:     
*/
ZEND_BEGIN_MODULE_GLOBALS(myfile)
	long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(myfile)

/* In every utility function you add that needs to use variables 
   in php_myfile_globals, call TSRMLS_FETCH(); after declaring other 
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as MYFILE_G(variable).  You are 
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#ifdef ZTS
#define MYFILE_G(v) TSRMG(myfile_globals_id, zend_myfile_globals *, v)
#else
#define MYFILE_G(v) (myfile_globals.v)
#endif

#endif	/* PHP_MYFILE_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
