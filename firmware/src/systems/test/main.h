#include "config.h"

#ifdef ENABLE_LOGGING
#include "hardware/logger/logger.h"
#endif

#ifdef ENABLE_DISPLAY
#include "hardware/display/display.h"
#endif

#ifdef ENABLE_BUTTON
#include "hardware/button/button.h"
#endif

#ifdef ENABLE_BEEPER
#include "hardware/beeper/beeper.h"
#endif

#ifdef ENABLE_AMBIENT
#include "hardware/ambient/ambient.h"
#endif

#ifdef ENABLE_IMAGE
#include "components/jpeg/Image.h"
#endif

#ifdef ENABLE_ANIMATION
#include "components/animation/animation.h"
#endif

#ifdef ENABLE_FSANIMATION
#include "components/fsAnimation/fsAnimation.h"
#endif

#ifdef ENABLE_FILESYSTEM
#define FS_NO_GLOBALS
#include <FS.h>
#endif
