CXX      := c++
CXXFLAGS := -g -MMD -MP -Wall -Wextra -Werror -std=c++98
DFLAGS   := -fsanitize=address -fsanitize=bounds
INCLUDE  := -I includes
NAME     := a.out
SRCDIR   := srcs
SRCS     := \
        srcs/Form.cpp \
        srcs/Bureaucrat.cpp \
        srcs/main.cpp
OBJDIR   := objs
OBJS     := $(subst $(SRCDIR), $(OBJDIR), $(SRCS:.cpp=.o))
DEPENDS  := $(OBJS:.o=.d)
BASE_DIR := $(CURDIR)
BUILD_DIR := build
BUILD_PATH := $(BASE_DIR)/$(BUILD_DIR)
TEST_EXE_PATH := $(BUILD_PATH)/cpp-test

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	$(CXX) -o $@ $^ $(INCLUDE) $(CXXFLAGS) $(if $(DEBUG),$(DFLAGS),)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@ mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(if $(DEBUG),$(DFLAGS),) $(INCLUDE) -o $@ -c $<

.PHONY: clean
clean:
	$(RM) -r $(OBJDIR)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: debug
debug:
	make DEBUG=1

# Run all tests
.PHONY: test
test:
	@# Ensure cmake runs to generate the test executable
	cmake -S $(BASE_DIR) -B $(BUILD_PATH)
	@# Build the project
	@cmake --build $(BUILD_PATH) || exit 1
	@# Execute the test
	@$(TEST_EXE_PATH) || exit 1

# Delete tests related files
.PHONY: test/clean
test/clean:
	$(RM) -r $(BUILD_PATH)

cppfile:
	find srcs -name "*.cpp" | sed 's/\.\///g' | awk '{print "\t"$$0" \\"}' | sed '$$s/ \\//'

-include $(DEPENDS)