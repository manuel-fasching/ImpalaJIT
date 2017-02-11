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

  !> @cond ingore
  interface
  !> @endcond ingore

    !> @internal

    !! ToDo: Wrapper. Trim auf config_path. c_null_char anhängen.
    function impalajit_compiler_create_with_config( config_path // c_null_char ) bind( c, name="impalajit_compiler_create_with_config" )
      use, intrinsic :: iso_c_binding
      character( kind=c_char ), dimension(*)       :: config_path
      type( c_ptr )                         :: impalajit_compiler_create_with_config
    end function impalajit_compiler_create_with_config


    !> @internal
    subroutine impalajit_compiler_compile( handle ) bind( c, name="impalajit_compiler_compile" )
      use, intrinsic :: iso_c_binding
      type( c_ptr )                         :: handle
    end subroutine impalajit_compiler_compile

    //ToDo: Call by Value
    !> @internal
    function impalajit_compiler_get_function( handle, function_name ) bind( c, name="impalajit_compiler_get_function" )
      use, intrinsic :: iso_c_binding
      type( c_ptr )                         :: handle
      character( kind=c_char, len=* )       :: function_name
      type( c_funptr )                      :: impalajit_compiler_get_function
    end function impalajit_compiler_get_function

    !> @cond ignore
    end interface
    !> @endcond ignore
end module impalajit