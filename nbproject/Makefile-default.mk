#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/PIC24F08KL200.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/PIC24F08KL200.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=Device/Convert/AnaToDigi.c Device/Serial/I2C.c Device/Serial/UART.c Device/Serial/SPI.c Device/Init.c Device/PWM.c Device/EEPROM.c User/Motor.c User/Battery.c main.c Interrupt.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/Device/Convert/AnaToDigi.o ${OBJECTDIR}/Device/Serial/I2C.o ${OBJECTDIR}/Device/Serial/UART.o ${OBJECTDIR}/Device/Serial/SPI.o ${OBJECTDIR}/Device/Init.o ${OBJECTDIR}/Device/PWM.o ${OBJECTDIR}/Device/EEPROM.o ${OBJECTDIR}/User/Motor.o ${OBJECTDIR}/User/Battery.o ${OBJECTDIR}/main.o ${OBJECTDIR}/Interrupt.o
POSSIBLE_DEPFILES=${OBJECTDIR}/Device/Convert/AnaToDigi.o.d ${OBJECTDIR}/Device/Serial/I2C.o.d ${OBJECTDIR}/Device/Serial/UART.o.d ${OBJECTDIR}/Device/Serial/SPI.o.d ${OBJECTDIR}/Device/Init.o.d ${OBJECTDIR}/Device/PWM.o.d ${OBJECTDIR}/Device/EEPROM.o.d ${OBJECTDIR}/User/Motor.o.d ${OBJECTDIR}/User/Battery.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/Interrupt.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/Device/Convert/AnaToDigi.o ${OBJECTDIR}/Device/Serial/I2C.o ${OBJECTDIR}/Device/Serial/UART.o ${OBJECTDIR}/Device/Serial/SPI.o ${OBJECTDIR}/Device/Init.o ${OBJECTDIR}/Device/PWM.o ${OBJECTDIR}/Device/EEPROM.o ${OBJECTDIR}/User/Motor.o ${OBJECTDIR}/User/Battery.o ${OBJECTDIR}/main.o ${OBJECTDIR}/Interrupt.o

# Source Files
SOURCEFILES=Device/Convert/AnaToDigi.c Device/Serial/I2C.c Device/Serial/UART.c Device/Serial/SPI.c Device/Init.c Device/PWM.c Device/EEPROM.c User/Motor.c User/Battery.c main.c Interrupt.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/PIC24F08KL200.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24F08KL200
MP_LINKER_FILE_OPTION=,--script=p24F08KL200.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/Device/Convert/AnaToDigi.o: Device/Convert/AnaToDigi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Device/Convert 
	@${RM} ${OBJECTDIR}/Device/Convert/AnaToDigi.o.d 
	@${RM} ${OBJECTDIR}/Device/Convert/AnaToDigi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Device/Convert/AnaToDigi.c  -o ${OBJECTDIR}/Device/Convert/AnaToDigi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Device/Convert/AnaToDigi.o.d"      -g -D__DEBUG     -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/Device/Convert/AnaToDigi.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Device/Serial/I2C.o: Device/Serial/I2C.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Device/Serial 
	@${RM} ${OBJECTDIR}/Device/Serial/I2C.o.d 
	@${RM} ${OBJECTDIR}/Device/Serial/I2C.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Device/Serial/I2C.c  -o ${OBJECTDIR}/Device/Serial/I2C.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Device/Serial/I2C.o.d"      -g -D__DEBUG     -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/Device/Serial/I2C.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Device/Serial/UART.o: Device/Serial/UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Device/Serial 
	@${RM} ${OBJECTDIR}/Device/Serial/UART.o.d 
	@${RM} ${OBJECTDIR}/Device/Serial/UART.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Device/Serial/UART.c  -o ${OBJECTDIR}/Device/Serial/UART.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Device/Serial/UART.o.d"      -g -D__DEBUG     -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/Device/Serial/UART.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Device/Serial/SPI.o: Device/Serial/SPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Device/Serial 
	@${RM} ${OBJECTDIR}/Device/Serial/SPI.o.d 
	@${RM} ${OBJECTDIR}/Device/Serial/SPI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Device/Serial/SPI.c  -o ${OBJECTDIR}/Device/Serial/SPI.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Device/Serial/SPI.o.d"      -g -D__DEBUG     -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/Device/Serial/SPI.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Device/Init.o: Device/Init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Device 
	@${RM} ${OBJECTDIR}/Device/Init.o.d 
	@${RM} ${OBJECTDIR}/Device/Init.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Device/Init.c  -o ${OBJECTDIR}/Device/Init.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Device/Init.o.d"      -g -D__DEBUG     -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/Device/Init.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Device/PWM.o: Device/PWM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Device 
	@${RM} ${OBJECTDIR}/Device/PWM.o.d 
	@${RM} ${OBJECTDIR}/Device/PWM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Device/PWM.c  -o ${OBJECTDIR}/Device/PWM.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Device/PWM.o.d"      -g -D__DEBUG     -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/Device/PWM.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Device/EEPROM.o: Device/EEPROM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Device 
	@${RM} ${OBJECTDIR}/Device/EEPROM.o.d 
	@${RM} ${OBJECTDIR}/Device/EEPROM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Device/EEPROM.c  -o ${OBJECTDIR}/Device/EEPROM.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Device/EEPROM.o.d"      -g -D__DEBUG     -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/Device/EEPROM.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/User/Motor.o: User/Motor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/User 
	@${RM} ${OBJECTDIR}/User/Motor.o.d 
	@${RM} ${OBJECTDIR}/User/Motor.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  User/Motor.c  -o ${OBJECTDIR}/User/Motor.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/User/Motor.o.d"      -g -D__DEBUG     -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/User/Motor.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/User/Battery.o: User/Battery.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/User 
	@${RM} ${OBJECTDIR}/User/Battery.o.d 
	@${RM} ${OBJECTDIR}/User/Battery.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  User/Battery.c  -o ${OBJECTDIR}/User/Battery.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/User/Battery.o.d"      -g -D__DEBUG     -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/User/Battery.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG     -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Interrupt.o: Interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Interrupt.o.d 
	@${RM} ${OBJECTDIR}/Interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Interrupt.c  -o ${OBJECTDIR}/Interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Interrupt.o.d"      -g -D__DEBUG     -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/Interrupt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/Device/Convert/AnaToDigi.o: Device/Convert/AnaToDigi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Device/Convert 
	@${RM} ${OBJECTDIR}/Device/Convert/AnaToDigi.o.d 
	@${RM} ${OBJECTDIR}/Device/Convert/AnaToDigi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Device/Convert/AnaToDigi.c  -o ${OBJECTDIR}/Device/Convert/AnaToDigi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Device/Convert/AnaToDigi.o.d"        -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/Device/Convert/AnaToDigi.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Device/Serial/I2C.o: Device/Serial/I2C.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Device/Serial 
	@${RM} ${OBJECTDIR}/Device/Serial/I2C.o.d 
	@${RM} ${OBJECTDIR}/Device/Serial/I2C.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Device/Serial/I2C.c  -o ${OBJECTDIR}/Device/Serial/I2C.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Device/Serial/I2C.o.d"        -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/Device/Serial/I2C.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Device/Serial/UART.o: Device/Serial/UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Device/Serial 
	@${RM} ${OBJECTDIR}/Device/Serial/UART.o.d 
	@${RM} ${OBJECTDIR}/Device/Serial/UART.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Device/Serial/UART.c  -o ${OBJECTDIR}/Device/Serial/UART.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Device/Serial/UART.o.d"        -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/Device/Serial/UART.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Device/Serial/SPI.o: Device/Serial/SPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Device/Serial 
	@${RM} ${OBJECTDIR}/Device/Serial/SPI.o.d 
	@${RM} ${OBJECTDIR}/Device/Serial/SPI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Device/Serial/SPI.c  -o ${OBJECTDIR}/Device/Serial/SPI.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Device/Serial/SPI.o.d"        -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/Device/Serial/SPI.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Device/Init.o: Device/Init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Device 
	@${RM} ${OBJECTDIR}/Device/Init.o.d 
	@${RM} ${OBJECTDIR}/Device/Init.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Device/Init.c  -o ${OBJECTDIR}/Device/Init.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Device/Init.o.d"        -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/Device/Init.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Device/PWM.o: Device/PWM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Device 
	@${RM} ${OBJECTDIR}/Device/PWM.o.d 
	@${RM} ${OBJECTDIR}/Device/PWM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Device/PWM.c  -o ${OBJECTDIR}/Device/PWM.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Device/PWM.o.d"        -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/Device/PWM.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Device/EEPROM.o: Device/EEPROM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Device 
	@${RM} ${OBJECTDIR}/Device/EEPROM.o.d 
	@${RM} ${OBJECTDIR}/Device/EEPROM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Device/EEPROM.c  -o ${OBJECTDIR}/Device/EEPROM.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Device/EEPROM.o.d"        -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/Device/EEPROM.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/User/Motor.o: User/Motor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/User 
	@${RM} ${OBJECTDIR}/User/Motor.o.d 
	@${RM} ${OBJECTDIR}/User/Motor.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  User/Motor.c  -o ${OBJECTDIR}/User/Motor.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/User/Motor.o.d"        -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/User/Motor.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/User/Battery.o: User/Battery.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/User 
	@${RM} ${OBJECTDIR}/User/Battery.o.d 
	@${RM} ${OBJECTDIR}/User/Battery.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  User/Battery.c  -o ${OBJECTDIR}/User/Battery.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/User/Battery.o.d"        -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/User/Battery.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d"        -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Interrupt.o: Interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Interrupt.o.d 
	@${RM} ${OBJECTDIR}/Interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Interrupt.c  -o ${OBJECTDIR}/Interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Interrupt.o.d"        -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/Interrupt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/PIC24F08KL200.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/PIC24F08KL200.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG   -omf=elf     -Wl,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/PIC24F08KL200.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/PIC24F08KL200.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -Wl,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}/xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/PIC24F08KL200.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
