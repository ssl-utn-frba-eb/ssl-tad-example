#include <stdio.h>
#include <stdbool.h>
#include <cspecs/cspec.h>
#include "stack.h"

context (Stack) {
  describe("Push") {
      StackIntPtr_t stack;

      before {
        stack = init_stack();
      } end
      
      after {
        destroy_stack(stack);
      } end

      it("Stack push should be pushing a value") {
        stack_push(stack, 52);
        should_int(peek_stack(stack, 0)) be equal to(52);
      } end

      it("stack push should be true") {
        should_bool(stack_push(stack, 52)) be equal to(true);
      } end
  } end

  describe("Pop") {
      StackIntPtr_t stack;
      int ret;

      before {
        stack = init_stack();
      } end
      
      after {
        destroy_stack(stack);
      } end

      it("Stack pop should be popping a previously pushed value") {
        stack_push(stack, 52);
        stack_pop(stack, &ret);
        should_int(ret) be equal to(52);
      } end

      it("stack pop should be true if there is a value already") {
        stack_push(stack, 52);
        should_bool(stack_pop(stack, &ret)) be equal to(true);
      } end

      it("stack pop should return false if no value is present") {
        should_bool(stack_pop(stack, &ret)) be equal to(false);
      } end
  } end
}