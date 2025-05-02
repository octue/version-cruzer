import test from 'node:test';
import { strict as assert } from 'node:assert';
import { version, getBaseDialect } from './cruzer.js';

test('const to enum', async (t) => {
  const from = {
    $schema: 'https://json-schema.org/draft/2020-12/schema',
    const: 'foo'
  };

  const to = {
    $schema: 'https://json-schema.org/draft/2020-12/schema',
    enum: [ 'foo', 'bar' ]
  };

  assert.deepStrictEqual(await version(from, to), {
    version: "minor",
    traces: [
      {
        compatibility: "incompatible",
        left: "/const",
        right: "/enum"
      }
    ]
  });
});

test('base dialect: 2020-12', async (t) => {
  const schema = {
    $schema: 'https://json-schema.org/draft/2020-12/schema',
    const: 'foo'
  };

  assert.deepStrictEqual(await getBaseDialect(schema),
    'https://json-schema.org/draft/2020-12/schema');
});

test('base dialect: draft7', async (t) => {
  const schema = {
    $schema: 'http://json-schema.org/draft-07/schema#',
    const: 'foo'
  };

  assert.deepStrictEqual(await getBaseDialect(schema),
    'http://json-schema.org/draft-07/schema#');
});

test('base dialect: unknown', async (t) => {
  const schema = {
    const: 'foo'
  };

  assert.deepStrictEqual(await getBaseDialect(schema), null);
});
