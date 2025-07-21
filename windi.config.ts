import { defineConfig } from 'windicss/helpers'

export default defineConfig({
  extract: {
    include: ['src/**/*.{tsx,ts,jsx,js,html}'],
  },
  darkMode: 'class', // если хочешь поддерживать тёмную тему
})
