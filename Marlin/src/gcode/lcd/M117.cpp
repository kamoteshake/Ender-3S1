/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include "../../inc/MarlinConfig.h"

#if HAS_STATUS_MESSAGE

#include "../gcode.h"
#include "../../lcd/marlinui.h"

#if ENABLED(RTS_AVAILABLE)
  #include "../../lcd/dwin/lcd_rts.h"
#endif

void ClearAbnormalPageText() {
  for (int i = 0; i <= SizeofDatabuf; i++) {
    rtscheck.RTS_SndData(0, ABNORMAL_PAGE_TEXT_VP + i);
  }
}

/**
 * M117: Set LCD Status Message
 */
void GcodeSuite::M117() {
  #if ENABLED(RTS_AVAILABLE)
    if (parser.string_arg && parser.string_arg[0]) {
      // save the current page to be able to go back to it
      int previousPage = change_page_font < 1 ? 1 : change_page_font;
      
      // change to the abnomal page
      rtscheck.RTS_SndData(ExchangePageBase + 41, ExchangepageAddr);
      change_page_font = 41;

      // reset status text before using just in case there were an error beforehand
      ClearAbnormalPageText();

      // format text if it's longer than the text length
      char statusText[SizeofDatabuf];
      if (strlen(parser.string_arg) >= SizeofDatabuf) {
        // copy the string to statusText
        strncpy(statusText, parser.string_arg, SizeofDatabuf - 1);
        // change the last 3 chars with ..\0
        strncpy(&statusText[SizeofDatabuf - 3], "..", 2);
        statusText[SizeofDatabuf - 1] = '\0';
      }
      else {
        strcpy(statusText, parser.string_arg);
      }

      // show status text
      rtscheck.RTS_SndData(statusText, ABNORMAL_PAGE_TEXT_VP);

      delay(3000);

      // return to previous page
      rtscheck.RTS_SndData(ExchangePageBase + previousPage, ExchangepageAddr);
      change_page_font = previousPage;

      // reset status text after for the next error handling
      ClearAbnormalPageText();
    }
  #else
    if (parser.string_arg && parser.string_arg[0])
      ui.set_status(parser.string_arg);
    else
      ui.reset_status();
  #endif
}

#endif // HAS_STATUS_MESSAGE
