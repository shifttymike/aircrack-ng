#ifndef _NET_EAPOL_H_
#define _NET_EAPOL_H_

#include <stdint.h>

/* Message bits in WPA_hdsk.found and WPA_hdsk.eapol_source. */
#define WPA_HANDSHAKE_M1 (1U << 1)
#define WPA_HANDSHAKE_M2 (1U << 2)
#define WPA_HANDSHAKE_M3 (1U << 3)
#define WPA_HANDSHAKE_M4 (1U << 4)

struct WPA_hdsk
{
	uint8_t stmac[6]; /* supplicant MAC           */
	uint8_t snonce[32]; /* supplicant nonce         */
	uint8_t anonce[32]; /* authenticator nonce      */
	uint8_t pmkid[16]; /* eapol frame PMKID RSN    */
	uint8_t keymic[16]; /* eapol frame MIC          */
	uint8_t eapol[256]; /* eapol frame contents     */
	uint32_t eapol_size; /* eapol frame size         */
	uint8_t keyver; /* key version (TKIP / AES) */
	uint8_t state; /* handshake completion     */
	uint8_t found;
	uint8_t eapol_source;
	uint64_t replay;
	uint64_t timestamp_start_us;
	uint64_t timestamp_last_us;
};

/*
 * A WPA handshake is usable only when the captured EAPOL frame belongs to a
 * crackable message pair.  Do not use state here: it deliberately groups M1
 * and M3 because both carry the authenticator nonce.
 */
static inline int wpa_handshake_is_usable(const struct WPA_hdsk * wpa)
{
	uint8_t found;
	uint8_t source;

	if (wpa == 0) return (0);
	found = wpa->found;
	source = wpa->eapol_source;

	return (((found & (WPA_HANDSHAKE_M1 | WPA_HANDSHAKE_M2))
			  == (WPA_HANDSHAKE_M1 | WPA_HANDSHAKE_M2)
			  && (source & WPA_HANDSHAKE_M2) != 0)
			|| ((found & (WPA_HANDSHAKE_M1 | WPA_HANDSHAKE_M4))
					== (WPA_HANDSHAKE_M1 | WPA_HANDSHAKE_M4)
				&& (source & WPA_HANDSHAKE_M4) != 0)
			|| ((found & (WPA_HANDSHAKE_M2 | WPA_HANDSHAKE_M3))
					== (WPA_HANDSHAKE_M2 | WPA_HANDSHAKE_M3)
				&& (source & (WPA_HANDSHAKE_M2 | WPA_HANDSHAKE_M3)) != 0)
			|| ((found & (WPA_HANDSHAKE_M3 | WPA_HANDSHAKE_M4))
					== (WPA_HANDSHAKE_M3 | WPA_HANDSHAKE_M4)
				&& (source & (WPA_HANDSHAKE_M3 | WPA_HANDSHAKE_M4)) != 0));
}

#endif // _NET_EAPOL_H_
