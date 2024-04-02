package schema

import (
	"math/big"
	"testing"

	"github.com/stretchr/testify/assert"
	"github.com/stretchr/testify/require"

	"go.ytsaurus.tech/yt/go/yson"
)

func TestDecimal(t *testing.T) {
	v, err := NewDecimalValueFromBigInt(big.NewInt(123456), 22, 9)
	require.NoError(t, err)

	ys, err := yson.Marshal(&v)
	require.NoError(t, err)

	var got DecimalValue
	require.NoError(t, yson.Unmarshal(ys, &got))
	assert.Equal(t, v, got)

	//a, err := DecodeDecimalValue(got, 22, 9)
	//require.NoError(t, err)
	//assert.Equal(t, v, a)
}

func TestDecimalDecode(t *testing.T) {
	v, err := NewDecimalValueFromBigInt(big.NewInt(2821000000000000), 35, 12)
	require.NoError(t, err)

	got, err := DecodeDecimalValue(v, 35, 12)
	require.NoError(t, err)

	assert.Equal(t, NewDecodedDecimalValueFromBigInt(big.NewInt(2821000000000000), 35, 12), got)
}

func TestDecimalExample(t *testing.T) {
	v, err := NewDecimalValueFromBigInt(big.NewInt(-27182), 1, 4)
	require.NoError(t, err)

	ys, err := yson.Marshal(&v)
	require.NoError(t, err)

	var got DecimalValue
	require.NoError(t, yson.Unmarshal(ys, &got))
	assert.Equal(t, v, got)

	a, err := DecodeDecimalValue(got, 1, 4)
	require.NoError(t, err)
	assert.Equal(t, v, a)
}

func TestYsonBytes(t *testing.T) {
	e := []byte{'\x7f', '\xff', '\x95', '\xd2'}
	serialized, err := yson.Marshal(e)
	require.NoError(t, err)
	require.NotNil(t, serialized)

	var got []byte
	require.NoError(t, yson.Unmarshal(serialized, &got))
	require.NotNil(t, got)
	require.Equal(t, got, e)

	decoded, err := DecodeDecimalValueFromBytes(got, 1, 4)
	require.NoError(t, err)
	require.NotNil(t, decoded)

	enc, err := decoded.Encode()
	require.NoError(t, err)
	require.NotNil(t, enc)
}
