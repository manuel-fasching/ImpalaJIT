!>
!! Copyright 2017 Manuel Fasching <manuel.fasching@tum.de>
!! Distributed under the MIT License
!!
!! Permission is hereby granted, free of charge, to any person obtaining a copy
!! of this software and associated documentation files (the "Software"), to deal
!! in the Software without restriction, including without limitation the rights
!! to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
!! copies of the Software, and to permit persons to whom the Software is furnished
!! to do so, subject to the following conditions:
!!
!! THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
!! INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
!! PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
!! FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
!! ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
!! THE SOFTWARE.
!!
module impalajit
  implicit none
  	abstract interface
	    function c_callback (a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20)
		    use, intrinsic :: iso_c_binding
		    real(c_double), intent(in), optional, value			:: a1, a2, a3, a4, a5, a6, a7, a8, a9, a10
		    real(c_double), intent(in), optional, value			:: a11, a12, a13, a14, a15, a16, a17, a18, a19, a20 
		    real(c_double) 										:: c_callback
		end function c_callback    
    end interface

    interface

        subroutine impalajit_compiler_compile( handle ) bind( c, name="impalajit_compiler_compile" )
            use, intrinsic :: iso_c_binding
            type( c_ptr ), value, intent(in)                    :: handle
        end subroutine impalajit_compiler_compile

        function impalajit_compiler_create_with_config_c( config_path ) bind( c, name="impalajit_compiler_create_with_config" )
          use, intrinsic :: iso_c_binding
          character( kind=c_char ), dimension(*), intent(in)    :: config_path
          type( c_ptr )                                         :: impalajit_compiler_create_with_config_c
        end function impalajit_compiler_create_with_config_c

        function impalajit_compiler_get_function_c( handle, function_name ) bind( c, name="impalajit_compiler_get_function" )
          use, intrinsic :: iso_c_binding
          type( c_ptr ), value, intent(in)                             :: handle
          character( kind=c_char ), dimension(*), intent(in)    :: function_name
          type( c_funptr )                                      :: impalajit_compiler_get_function_c
        end function impalajit_compiler_get_function_c

    end interface

  	contains

		function impalajit_compiler_create_with_config( config_path )
            use, intrinsic :: iso_c_binding
            character*(*), intent(in)                           :: config_path
            type( c_ptr )                                       :: impalajit_compiler_create_with_config

            impalajit_compiler_create_with_config = impalajit_compiler_create_with_config_c( trim(config_path) // c_null_char )
        end function impalajit_compiler_create_with_config

		function impalajit_compiler_get_function( handle, function_name )
            use, intrinsic :: iso_c_binding
            type( c_ptr ), value, intent(in)                    :: handle
            character*(*), intent(in)                           :: function_name
            type( c_funptr )                                    :: impalajit_compiler_get_function

            impalajit_compiler_get_function = impalajit_compiler_get_function_c( handle, trim(function_name) // c_null_char )
        end function impalajit_compiler_get_function    	

end module impalajit