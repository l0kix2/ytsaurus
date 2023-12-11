package internal

import (
	"crypto/sha256"
	"fmt"
)

func EncodeSHA256(input string) string {
	return fmt.Sprintf("%x", sha256.Sum256([]byte(input)))
}
