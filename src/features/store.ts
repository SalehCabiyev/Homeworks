import { configureStore } from '@reduxjs/toolkit';

export const store = configureStore({
  reducer: {
    // auth: authReducer,
    // posts: postsReducer
  }
});

export type RootState = ReturnType<typeof store.getState>;
export type AppDispatch = typeof store.dispatch;