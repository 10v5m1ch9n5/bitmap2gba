# ==================== PROJECT OPTIONS ====================

TARGET   := $(notdir $(CURDIR))
SOURCES  := src
INCLUDES := include
BUILD    := build

CC := gcc
CFLAGS := -Wall -std=c99
LD := $(CC)
LDFLAGS := $(CFLAGS)


ifeq ($(notdir $(CURDIR)),$(BUILD))

$(OUTPUT).elf : $(OFILES)
	$(LD) $(LDFLAGS) $^ -o $@

$(OFILES) : %.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

else

export CFILES := $(foreach dir, $(SOURCES), $(notdir $(wildcard $(dir)/*.c)))
export OFILES := $(CFILES:.c=.o)
export VPATH  := $(foreach dir, $(SOURCES), $(CURDIR)/$(dir))
export OUTPUT := $(CURDIR)/$(TARGET)

$(BUILD):
	@[ -d $@ ] || mkdir -p $@
	@$(MAKE) -C $(BUILD) -f $(CURDIR)/Makefile

clean:
	@rm -rf $(BUILD) $(TARGET).elf

.PHONY: $(BUILD) clean

endif
